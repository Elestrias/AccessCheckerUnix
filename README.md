# **Unix system access checker util (USACu)**
***
## Description
Simple util to check user access for changing files and directories in unix filesystem  

## Dependencies
- -std=c++2a
- -lstdc++fs
## Run instructions
 - Run Makefile 
 - Run in Terminal ```sudo ./main -u username -g groupname -p /path/to/be/inserted/here/```
***
## Development notes
- [x] Create argument parser
- [x] **Make system reader(SR)**
- [x] Make SR recursive
- [x] Make etc/passwd and etc/group files reader
- [x] **Make permissions checker**
- [x] Change architecture wih applying to be expandable    
- [x] Change SR with applying not to be dropped by "permission denied" error
- [x] **Create Makefile**
- [x] **Wrap util as the deb package**
- [ ] Extend util to the **Linux: $ ls** service
***

## Code Description

- **class AccessChecker** - is the main body of the util, it provides functions to set configuration of the process, to make checks and to output results;
    * **func getFiles** - going thought packages and files and outputting results for every met files and directories;
    * **func CheckUser** - checking user permission for changing provided by reference file or directory;
    * **func setConfigs** - evaluating possibility of changing session variables(user id, group id) and make this changes;
- **tools** - is a set of functions which are created for input parsing and validation;
