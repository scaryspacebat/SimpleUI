#ifndef HASSETTINGS_H
#define HASSETTINGS_H

#include "setting.h"

#include <vector>
#include <string>

class hasSettings
{
    public:
        hasSettings();
        virtual ~hasSettings();

        void addSetting(setting* s);

        void loadSettingsFromFile(std::string filename);

        void saveSettingsToFile(std::string filename);

    protected:
        std::vector<setting*> settings;

    private:
};

#endif // HASSETTINGS_H
