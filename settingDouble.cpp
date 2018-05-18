#include "settingDouble.h"

#include <cmath>

settingDouble::settingDouble(std::string n, double d) : setting(n), defaultDouble(d)
{
    //ctor
    doubleVal=defaultDouble;
}

settingDouble::~settingDouble()
{
    //dtor
}

void settingDouble::loadValueFromString(std::string in){
    doubleVal=std::stod(in);
    return;
}

std::string settingDouble::getStringValue(){
    return std::to_string(doubleVal);
}

int settingDouble::getIntegerValue(){
    return floor(doubleVal);
}

bool settingDouble::getBooleanValue(){
    if(doubleVal==0) return false;
    return true;
}

double settingDouble::getDoubleValue(){
    return doubleVal;
}
