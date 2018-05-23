#ifndef SETTINGSTRING_H
#define SETTINGSTRING_H

#include "settingBase.hpp"


class settingString : public setting {
public:
    settingString( std::string n, std::string dv );
    virtual ~settingString();

    void loadValueFromString( std::string in );

    std::string getStringValue();
    int getIntegerValue();
    bool getBooleanValue();
    double getDoubleValue();

    void setStringValue( std::string i );

protected:
    std::string strValue;
    std::string defaultString;

private:
};

#endif // SETTINGSTRING_H
