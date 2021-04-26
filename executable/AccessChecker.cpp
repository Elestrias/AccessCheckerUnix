#include "../headers/AccessChecker.h"

void AccessChecker::getFiles(string& path){
    for (const auto &it : filesystem::recursive_directory_iterator(path,
                                                                    static_cast<filesystem::directory_options>(2))) {
        if (CheckUser(static_cast<string>(it.path()))){
            if (experimental::filesystem::is_regular_file(it.path())) {
                cout << "f " << it.path() << "\n";
            } else if (experimental::filesystem::is_directory(it.path())) {
                cout << "d " << it.path() << "\n";
            }
        }

    }
}

bool AccessChecker::CheckUser(string path){
    int ret = access(path.c_str(), W_OK) == 0;
    return ret;
}

bool AccessChecker::setConfigs(string &username, string &groupname) {
    //cout<<"Cur ID"<<getuid()<<"\n";
    //cout<<"Cur grID"<<getgid()<<"\n";
    auto user = getpwnam(username.c_str());

    if(user == NULL){
        cout<<"ERROR: User does not exist or was not passed to a program\n";
        return false;
    }

    auto group = getgrnam(groupname.c_str());

    if(group == NULL){
        cout<<"ERROR: Group does not exist or was not passed to a program\n";
        return false;
    }

    int i = 0;
    bool flag = false;

    while(group->gr_mem[i] != nullptr){
        if(strcmp(group->gr_mem[i], username.c_str()) == 0){
            flag = true;
        }
        ++i;
    }

    if(!flag){
        cout<<"ERROR: User does not belong to the provided group\n";
        return false;
    }

    if(setgid(group->gr_gid) == -1 || setuid(user->pw_uid) == -1){
        cout<<"ERROR: "<<strerror(errno)<<"\n";
        return false;
    }
    //cout<<"New ID"<<getuid()<<"\n";
    //cout<<"New grID"<<getgid()<<"\n";
    return true;
}