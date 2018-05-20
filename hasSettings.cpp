#include "hasSettings.h"

#include "log.h"

hasSettings::hasSettings()
{
    //ctor
}

hasSettings::~hasSettings()
{
    //dtor
}

void hasSettings::addSetting(setting* s)
{
    settings.push_back(s);
    return;
}

void hasSettings::loadSettingsFromFile(std::string filename)
{
    log::writeToLog("Loading Settings from "+filename, 1);
    log::addTab();
    std::ifstream file;
    std::vector<int> initialized;
    initialized.resize(settings.size());
    file.open(filename, std::ios::in); // open file
    if(file.is_open())
    {
        while(!file.eof())  // while end of file not reached
        {
            std::string line = "";
            getline(file, line, '\n'); // read in a line
            //log::writeToLog(line);
            if(line.substr(0, 1)!="#" && line.size()>3)  // if it's not a comment or empty
            {
                int equPos=line.find("=");
                int counter=0;
                log::writeToLog("Found "+line.substr(0, equPos), 3);
                bool foundSomething=false;
                while(counter<settings.size())  // go through settings until the name matches
                {
                    if(settings[counter]->getName()==line.substr(0, equPos))
                    {
                        settings[counter]->loadValueFromString(line.substr(equPos+1, line.size()-1));
                        log::writeToLog("Using value "+line.substr(equPos+1, line.size()-1), 3);
                        initialized[counter]++;
                        counter=settings.size(); // load the next line
                        foundSomething=true;
                    }
                    //else log::writeToLog("not "+settings[counter]->getName());
                    counter++;
                }
                if(!foundSomething)
                {
                    log::writeToLog("Did not find a setting called "+line.substr(0, equPos), 1);
                }
            }
        }
        file.close(); // close file
        for(int i=0; i<initialized.size(); i++){
            if(initialized[i]==0){
                log::writeToLog("Setting "+settings[i]->getName()+" hasn't been initialized", 1);
            }
            else if(initialized[i]>1){
                log::writeToLog("Setting "+settings[i]->getName()+" has been initialized multiple times", 1);
            }
        }
    }
    else
    {
        log::writeToLog("Couldn't load settings from "+filename, -1);
    }
    log::removeTab();
    log::nextLine();
    return;
}

void hasSettings::saveSettingsToFile(std::string filename)
{

    return;
}
