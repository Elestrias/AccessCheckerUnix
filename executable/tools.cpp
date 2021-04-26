#include "../headers/tools.h"

void argParser(int &argc, char **argv, string& user, string& group, string& path){
    for(int i = 1; i < argc; ++i){
        if(strcmp(argv[i], "-u") == 0){
            user = argv[++i];
        }else if(strcmp(argv[i], "-g") == 0){
            group = argv[++i];
        }else if(strcmp(argv[i], "-p") == 0){
            path = argv[++i];
        }
    }
}

bool checkPath(string& path){
    if(path == ""){
        return false;
    }
    cmatch result;
    regex regularSys("(/sys*)|(/proc*)");
    if(regex_match(path.c_str(), result, regularSys)){
        cout<<"Invalid path, you have no permission to check /sys and /proc";
        return false;
    }
    return true;
}

