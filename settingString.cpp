#include "settingString.h"

settingString::settingString(std::string n, std::string dv) : setting(n), defaultString(dv)
{
    //ctor
    strValue=defaultString;
}

settingString::~settingString()
{
    //dtor
}

void settingString::loadValueFromString(std::string in){
    strValue=in; // maybe do some cleanup and trimming
    return;
}

std::string settingString::getStringValue(){
    return strValue;
}

int settingString::getIntegerValue(){
    return std::stoi(strValue);
}

bool settingString::getBooleanValue(){
    if(strValue=="true") return true;
    return false;
}

double settingString::getDoubleValue(){
    return std::stod(strValue);
}


void settingString::setStringValue(std::string i){
    strValue=i;
}

