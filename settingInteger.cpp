#include "settingInteger.h"

settingInteger::settingInteger(std::string n, int i) : setting(n), defaultInt(i)
{
    //ctor
    intValue=defaultInt;
}

settingInteger::~settingInteger()
{
    //dtor
}

void settingInteger::loadValueFromString(std::string in){
    intValue=std::stoi(in);
    return;
}

std::string settingInteger::getStringValue(){
    return std::to_string(intValue);
}

int settingInteger::getIntegerValue(){
    return intValue; // needs some work
}

bool settingInteger::getBooleanValue(){
    if(intValue==0) return false;
    return true;
}

double settingInteger::getDoubleValue(){
    return static_cast<double>(intValue);
}

void settingInteger::setIntegerValue(int i){
    intValue=i;
}
