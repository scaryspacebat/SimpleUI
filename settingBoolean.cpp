#include "settingBoolean.h"

settingBoolean::settingBoolean(std::string n, bool d) : setting(n), defaultBool(d)
{
    //ctor
    boolVal=defaultBool;
}

settingBoolean::~settingBoolean()
{
    //dtor
}

void settingBoolean::loadValueFromString(std::string in){
    if(in=="true") boolVal=true;
    else boolVal=false;
    return;
}

std::string settingBoolean::getStringValue(){
    if(boolVal==true) return "true";
    return "false";
}

int settingBoolean::getIntegerValue(){
    if(boolVal==true) return 1;
    return 0;
}

bool settingBoolean::getBooleanValue(){
    return boolVal;
}

double settingBoolean::getDoubleValue(){
    if(boolVal==true) return 1.0f;
    return 0.0f;
}
