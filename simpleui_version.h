#ifndef SIMPLEUI_VERSION_H
#define SIMPLEUI_VERSION_H

namespace SimpleUIVersion{
	
	//Date Version Types
	static const char DATE[] = "23";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2018";
	static const char UBUNTU_VERSION_STYLE[] =  "18.05";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 251;
	static const long REVISION  = 1384;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 274;
	#define RC_FILEVERSION 1,2,251,1384
	#define RC_FILEVERSION_STRING "1, 2, 251, 1384\0"
	static const char FULLVERSION_STRING [] = "1.2.251.1384";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 51;
	

}
#endif //SIMPLEUI_VERSION_H
