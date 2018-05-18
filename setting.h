#ifndef SETTING_H
#define SETTING_H

#include <string>


class setting
{
    public:
        setting(std::string n);
        virtual ~setting();

        std::string getName();

        virtual void loadValueFromString(std::string in) = 0;

        virtual std::string getStringValue() = 0;
        virtual int getIntegerValue() = 0;
        virtual double getDoubleValue() = 0;
        virtual bool getBooleanValue() = 0;

    protected:
        std::string name;

    private:
};

#endif // SETTING_H
