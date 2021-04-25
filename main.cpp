#include "dependencies.h"


class AccessChecker{
public:
    AccessChecker(){};
    void getFiles(string& path, string &user, string& group){
        std::experimental::filesystem::file_type k;
        for (auto it : filesystem::recursive_directory_iterator(path))
        {
        if(CheckUser(user, path, group)) {
            if (experimental::filesystem::is_regular_file(it.path())) {
                cout << "f " << it.path() << "\n";
            } else if (experimental::filesystem::is_directory(it.path())) {
                cout << "d " << it.path() << "\n";
            }
          }
        }
    }
    bool CheckUser(string &username, string & path, string &groupname){
        cout<<"Cur ID"<<getuid()<<"\n";
        cout<<"Cur grID"<<getgid()<<"\n";

        auto user = getpwnam(username.c_str());
        auto group = getgrnam(groupname.c_str());

        if(user == NULL || setuid(user->pw_uid) == -1 || group == NULL || setgid(group->gr_gid) == -1){
            cout<<"Fatal access error"<<"\n";
            return false;
        }

        cout<<"New ID"<<getuid()<<"\n";
        cout<<"New grID"<<getgid()<<"\n";

        int ret = access(path.c_str(), W_OK) == 0;
        setuid(0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string input, username, path, groupname;
    for(int i = 1; i < argc; ++i){
        if(strcmp(argv[i], "-u") == 0){
            username = argv[++i];
        }else if(strcmp(argv[i], "-g") == 0){
            groupname = argv[++i];
        }else if(strcmp(argv[i], "-p") == 0){
            path = argv[++i];
        }
    }
    path = "/home/elestrias/CLionProjects/";
    AccessChecker* acc = new AccessChecker();
    acc->getFiles(path);
    return 0;
}