#include "../headers/dependencies.h"
#include "../headers/tools.h"
#include "../headers/AccessChecker.h"


int main(int argc, char *argv[]) {
    string username, groupname, path;
    argParser(argc, argv, username, groupname, path);
    if(checkPath(path, true) && AccessChecker::setConfigs(username, groupname)) {
        AccessChecker::getFiles(path);
    }else{
        cout<<"ERROR: Please pass valid arguments"<<"\n";
    }
    return 0;
}