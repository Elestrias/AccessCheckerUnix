#include "../headers/dependencies.h"
#include "../headers/tools.h"
#include "../headers/AccessChecker.h"


int main(int argc, char *argv[]) {
    auto [username, path, groupname] = argParser(argc, argv);
    path = "/home/elestrias/CLionProjects/";
    AccessChecker::getFiles(path, username, groupname);
    return 0;
}