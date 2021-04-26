#include "../headers/dependencies.h"
#include "../headers/tools.h"
#include "../headers/AccessChecker.h"


int main(int argc, char *argv[]) {
    string username, groupname, path;
    argParser(argc, argv, username, groupname, path);
    //path = "/home/elestrias/CLionProjects/";
    //username = "Sveta";
    //groupname = "TestGroup";
    if(checkPath(path) && AccessChecker::setConfigs(username, groupname)) {
        AccessChecker::getFiles(path);
    }else{
        cout<<"ERROR: Please pass valid arguments"<<"\n";
    }
    return 0;
}