#include "../headers/dependencies.h"
#include "../headers/tools.h"
#include "../headers/AccessChecker.h"


int main(int argc, char *argv[]) {
    vector<string> arguments = argParser(argc, argv);
    string username, groupname, path;
    username = arguments[0];
    groupname = arguments[1];
    path = arguments[2];
    //path = "/home/elestrias/CLionProjects/";
    //username = "Sveta";
    //groupname = "TestGroup";
    AccessChecker::getFiles(path, username, groupname);
    return 0;
}