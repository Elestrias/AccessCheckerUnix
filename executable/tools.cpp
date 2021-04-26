#include "../headers/tools.h"

vector<string> argParser(int &argc, char **argv){
    vector<string> arguments(3);
    for(int i = 1; i < argc; ++i){
        if(strcmp(argv[i], "-u") == 0){
            arguments[0] = argv[++i];
        }else if(strcmp(argv[i], "-g") == 0){
            arguments[1]= argv[++i];
        }else if(strcmp(argv[i], "-p") == 0){
            arguments[2] = argv[++i];
        }
    }
    return arguments;
}

bool checkPath(string& path){
    cmatch result;
    regex regularSys("(sys/*)|(proc/*)");
    return !regex_match(path.c_str(), result, regularSys);
}