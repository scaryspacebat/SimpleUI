#ifndef SETTINGDOUBLE_H
#define SETTINGDOUBLE_H

#include "settingBase.hpp"


class settingDouble : public setting {
public:
    settingDouble( std::string n, double d );
    virtual ~settingDouble();

    void loadValueFromString( std::string in );

    std::string getStringValue();
    int getIntegerValue();
    bool getBooleanValue();
    double getDoubleValue();

protected:
    double doubleVal;
    double defaultDouble;

private:
};

#endif // SETTINGDOUBLE_H
