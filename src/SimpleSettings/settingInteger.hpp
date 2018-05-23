#ifndef SETTINGINTEGER_H
#define SETTINGINTEGER_H

#include "settingBase.hpp"


class settingInteger : public setting {
public:
    settingInteger( std::string n, int i );
    virtual ~settingInteger();

    void loadValueFromString( std::string in );

    std::string getStringValue();
    int getIntegerValue();
    bool getBooleanValue();
    double getDoubleValue();

    void setIntegerValue( int i );

protected:
    int intValue;
    int defaultInt;

private:
};

#endif // SETTINGINTEGER_H
