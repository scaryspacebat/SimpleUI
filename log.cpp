#include "log.h"

#include "simpleui_version.h"

#include <iostream>
#include <fstream>
#include <string>

bool log::start=true;
int log::tabs=0;
int log::tresh=10;
std::fstream log::file;

void log::writeToLog(std::string out, int lvl)
{
    if(lvl<=tresh)
    {
        if(start)
        {
            file.open("logs/log.txt", std::ios::out | std::ios::trunc);
            writeLine("Starting log.txt at ");
            writeLine("Using SimpleUI v."+std::string(SimpleUIVersion::FULLVERSION_STRING));
            start=false;
        }
        else
        {
            file.open("logs/log.txt", std::ios::out | std::ios::app);
        }

        for(int i=0; i<tabs*4; i++)
        {
            if(i%4==0){
                    write("|");
            }
            else{
                    write(" ");
            }
        }

        if(lvl<0) {
            write("[ERROR] ");
        }
        writeLine(out);

        file.close();
    }
    return;
}

void log::addTab()
{
    tabs++;
    return;
}

void log::removeTab()
{
    tabs--;
    return;
}

void log::setTreshold(int tr)
{
    tresh=tr;
    return;
}

void log::nextLine(){
    writeToLog(" ");
    return;
}

void log::write(std::string out){
    file<<out;
    std::cout<<out;
    return;
}

void log::writeLine(std::string out){
    file<<out<<std::endl;
    std::cout<<out<<std::endl;
    return;
}
