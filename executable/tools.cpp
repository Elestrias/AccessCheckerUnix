#include "../headers/tools.h"

tuple<string, string, string> argParser(int &argc, char *argv[]){
    tuple<string, string, string> arguments;
    for(int i = 1; i < argc; ++i){
        if(strcmp(argv[i], "-u") == 0){
            get<0>(arguments) = argv[++i];
        }else if(strcmp(argv[i], "-g") == 0){
            get<1>(arguments)= argv[++i];
        }else if(strcmp(argv[i], "-p") == 0){
            get<2>(arguments) = argv[++i];
        }
    }
    return arguments;
}