#include "../headers/tools.h"

void argParser(int &argc, char **argv, string& user, string& group, string& path){
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "-u") == 0) {
                if(i < argc - 1) {
                    user = argv[++i];
                }
            } else if (strcmp(argv[i], "-g") == 0) {
                if(i < argc - 1) {
                    group = argv[++i];
                }
            } else if (strcmp(argv[i], "-p") == 0) {
                if(i < argc - 1) {
                    path = argv[++i];
                }
            }
        }
}

bool checkPath(string path, bool argument=false){
    cmatch result;
        if (path == "") {
            if (argument) {
                cout << "ERROR: Path does not exist or was not passed to a program\n";
            }
            return false;
        }
        regex regularSys("(/sys.*)|(/proc.*)");
        if (regex_match(path.c_str(), result, regularSys)) {
            if (argument) {
                cout << "ERROR: You have no access to check /proc and /sys\n";
            }
            return false;
        }
        return true;
}


