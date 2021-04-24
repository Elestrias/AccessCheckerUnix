#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <vector>
namespace filesystem = std::experimental::filesystem;
using namespace std;
struct passwd{

};

struct group{

};
class AccessChecker{
     int lstat(const char *pathname, struct stat *buf);
     passwd *getpwnam(const char *name);
     passwd *getpwuid(uid_t uid);
     group *getgrnam(const char *name);
public:
    AccessChecker();
     void getFiles(string path){
         for (auto it : filesystem::recursive_directory_iterator(path))
         {
            cout<<it.path()<<"\n";
         }
     }
};



int main() {
    string input, username, direcotry, groupname;
    cin>>input;
    AccessChecker* acc = new AccessChecker();
    acc->getFiles(input);
    return 0;
}
