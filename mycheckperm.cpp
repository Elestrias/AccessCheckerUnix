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

int main() {
    string input, username, direcotry, groupname;
    cin>>input;
    AccessChecker* acc = new AccessChecker();
    acc->getFiles(input);
    return 0;
}
