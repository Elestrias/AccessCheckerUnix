#include "dependencies.h"

#ifndef APP_ACCESSCHECKER_H
#define APP_ACCESSCHECKER_H


class AccessChecker {
public:
    static void getFiles(string&, string &, string&);
private:
    static bool CheckUser(string &, string, string &);
};


#endif //APP_ACCESSCHECKER_H
