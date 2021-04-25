#include "../headers/AccessChecker.h"

void AccessChecker::getFiles(string& path, string &user, string& group){
    if(path != "/sys" && path != "/proc") {
        for (const auto &it : filesystem::recursive_directory_iterator(path)) {
            if (CheckUser(user, static_cast<string>(it.path()), group)){
                if (experimental::filesystem::is_regular_file(it.path())) {
                    cout << "f " << it.path() << "\n";
                } else if (experimental::filesystem::is_directory(it.path())) {
                    cout << "d " << it.path() << "\n";
                }
            }

        }
    }
}

bool AccessChecker::CheckUser(string &username, string path, string &groupname){
    //cout<<"Cur ID"<<getuid()<<"\n";
    //cout<<"Cur grID"<<getgid()<<"\n";

    auto user = getpwnam(username.c_str());
    auto group = getgrnam(groupname.c_str());

    if(user == NULL || setgid(group->gr_gid) == -1 || group == NULL || setuid(user->pw_uid) == -1){
        return false;
    }

    //cout<<"New ID"<<getuid()<<"\n";
    //cout<<"New grID"<<getgid()<<"\n";

    int ret = access(path.c_str(), W_OK) == 0;
    setuid(0);
    setgid(0);
    return ret;
}