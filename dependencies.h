#ifndef APP_DEPENDENCIES_H
#define APP_DEPENDENCIES_H
#include <iostream>
#include <string>
#include <experimental/filesystem> // work with unix filesystem
#include <vector>
#include <cstring>
#include <pwd.h> //get user info from passwd
#include <grp.h> // get group info from passwd
#include <sys/types.h> // work with unix system files and functions
#include <unistd.h>
#include <grp.h> //set groups
namespace filesystem = std::experimental::filesystem;
using namespace std;
#endif //APP_DEPENDENCIES_H
