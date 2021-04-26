#include "dependencies.h"

#ifndef APP_ACCESSCHECKER_H
#define APP_ACCESSCHECKER_H


class AccessChecker {
public:

   static void getFiles(string&);
   static bool setConfigs(string&, string&);
   static bool resetConfigs(string&, string&);
private:
    static bool CheckUser(string);

};


#endif //APP_ACCESSCHECKER_H
