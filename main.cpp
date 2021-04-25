#include "dependencies.h"


class AccessChecker{
public:
    AccessChecker(){};
    void getFiles(string path){
        std::experimental::filesystem::file_type k;
        for (auto it : filesystem::recursive_directory_iterator(path))
        {
           if(experimental::filesystem::is_regular_file(it.path())) {
               cout << "f " << it.path() << "\n";
           }else if(experimental::filesystem::is_directory(it.path())){
                cout<<"d "<<it.path()<<"\n";
            }
        }
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

    //auto user = getpwnam(username.c_str());
    auto user = getpwnam("elestrias");
    //auto group = getgrnam(groupname.c_str());
    path = "/home/elestrias/CLionProjects/";
    AccessChecker* acc = new AccessChecker();
    acc->getFiles(path);
    return 0;
}