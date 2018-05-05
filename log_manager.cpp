#include <fstream>
#include <string>
#include "log_manager.h"
#include <iostream>

using namespace std;

bool log_manager::s=true;
int log_manager::t=0;
int log_manager::tresh=10;
int log_manager::lvl=1;
fstream log_manager::file;

void log_manager::write_log(string o, bool e)
{
    if(e || lvl<=tresh)
    {
        if(s)
        {
            file.open("logs/log.txt", ios::out | ios::trunc);
            file<<"Starting log.txt"<<endl;
            cout<<"Starting log.txt"<<endl;
            s=false;
        }
        else
        {
            file.open("logs/log.txt", ios::out | ios::app);
        }

        for(int i=0; i<t*3; i++)
        {
            if(i==0) file<<"+";
            else file<<"-";
            if(i==0) cout<<"+";
            else cout<<"-";
        }

        if(e) file<<"[ERROR] ";
        if(e) file<<"[ERROR] ";
        file<<o<<endl;
        cout<<o<<endl;
        file.close();
    }
    return;
}

void log_manager::write_log(string o, double v, bool e)
{
    if(e || lvl<=tresh)
    {
        if(s)
        {
            file.open("logs/log.txt", ios::out | ios::trunc);
            file<<"starting log.txt"<<endl;
            s=false;
        }
        else
        {
            file.open("logs/log.txt", ios::out | ios::app);
        }

        for(int i=0; i<t*3; i++)
        {
            if(i==0) file<<"+";
            else file<<"-";
        }

        //file.setf( std::ios::fixed, std:: ios::floatfield );
        //file.precision(10);

        if(e) file<<"[ERROR] ";
        file<<o<<v<<endl;
        file.close();
    }
    return;
}

void log_manager::add_tab()
{
    t++;
    return;
}

void log_manager::remove_tab()
{
    t--;
    return;
}

void log_manager::set_treshold(int tr)
{
    tresh=tr;
    return;
}

void log_manager::raise_level(int l)
{
    lvl+=l;
    return;
}

void log_manager::lower_level(int l)
{
    lvl-=l;
    return;
}
