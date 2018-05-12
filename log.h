#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <string>

class log
{
public:
    static void writeToLog(std::string out, int lvl=0);
    static void addTab();
    static void removeTab();
    static void setTreshold(int tr);
    static void raiseLevel(int l);
    static void lowerLevel(int l);
    static void nextLine();

private:
    static void write(std::string out);
    static void writeLine(std::string out);

    static bool start;
    static int tabs;
    static int tresh;
    static std::fstream file;

};

#endif // LOG_H
