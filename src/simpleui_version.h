#ifndef SIMPLEUI_VERSION_H
#define SIMPLEUI_VERSION_H

namespace SimpleUIVersion {

//Date Version Types
static const char DATE[] = "17";
static const char MONTH[] = "05";
static const char YEAR[] = "2018";
static const char UBUNTU_VERSION_STYLE[] =  "18.05";

//Software Status
static const char STATUS[] =  "Alpha";
static const char STATUS_SHORT[] =  "a";

//Standard Version Type
static const long MAJOR  = 1;
static const long MINOR  = 0;
static const long BUILD  = 75;
static const long REVISION  = 436;

//Miscellaneous Version Types
static const long BUILDS_COUNT  = 86;
#define RC_FILEVERSION 1,0,75,436
#define RC_FILEVERSION_STRING "1, 0, 75, 436\0"
static const char FULLVERSION_STRING [] = "1.0.75.436";

//These values are to keep track of your versioning state, don't modify them.
static const long BUILD_HISTORY  = 75;


}
#endif //SIMPLEUI_VERSION_H
