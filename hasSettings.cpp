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

void hasSettings::addSetting(setting* s){
    settings.push_back(s);
    return;
}

void hasSettings::loadSettingsFromFile(std::string filename){
    log::writeToLog("Loading Settings from "+filename);
    log::addTab();
    std::ifstream file;
    file.open(filename, std::ios::in); // open file
    if(file.is_open()){
    while(!file.eof()){ // while end of file not reached
        std::string line = "";
        getline(file, line, '\n'); // read in a line
        //log::writeToLog(line);
        if(line.substr(0, 1)!="#" && line.size()>3){ // if it's not a comment or empty
            int equPos=line.find("=");
            int counter=0;
            log::writeToLog("Found "+line.substr(0, equPos));
            while(counter<settings.size()){ // go through settings until the name matches
                if(settings[counter]->getName()==line.substr(0, equPos)){
                    settings[counter]->loadValueFromString(line.substr(equPos+1, line.size()-1));
                    log::writeToLog("Using value "+line.substr(equPos+1, line.size()-1));
                    counter=settings.size(); // load the next line
                }
                //else log::writeToLog("not "+settings[counter]->getName());
                counter++;
            }
        }
    }
    file.close(); // close file
    }
    else{
        log::writeToLog("Couldn't load settings from "+filename, -1);
    }
    log::removeTab();
    log::writeToLog("Finished Loading Settings");
    log::nextLine();
    return;
}

void hasSettings::saveSettingsToFile(std::string filename){

    return;
}
