#ifndef SIMPLEUI_VERSION_H
#define SIMPLEUI_VERSION_H

namespace SimpleUIVersion{
	
	//Date Version Types
	static const char DATE[] = "04";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2018";
	static const char UBUNTU_VERSION_STYLE[] =  "18.06";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 264;
	static const long REVISION  = 1462;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 287;
	#define RC_FILEVERSION 1,2,264,1462
	#define RC_FILEVERSION_STRING "1, 2, 264, 1462\0"
	static const char FULLVERSION_STRING [] = "1.2.264.1462";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 64;
	

}
#endif //SIMPLEUI_VERSION_H
