#ifndef SETTINGBOOLEAN_H
#define SETTINGBOOLEAN_H

#include "setting.h"


class settingBoolean : public setting
{
    public:
        settingBoolean(std::string, bool d);
        virtual ~settingBoolean();

        void loadValueFromString(std::string in);

        std::string getStringValue();
        int getIntegerValue();
        bool getBooleanValue();
        double getDoubleValue();

    protected:
        bool boolVal;
        bool defaultBool;

    private:
};

#endif // SETTINGBOOLEAN_H
