#include "setting.h"

setting::setting(std::string n)
{
    //ctor
    name=n;
}

setting::~setting()
{
    //dtor
}

std::string setting::getName(){
    return name;
}

