#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H
#include <fstream>
#include <string>

using namespace std;

class log_manager
{
public:
    static bool s;
    static void write_log(string o, bool e=false);
    static void write_log(string o, double v, bool e=false);
    static void add_tab();
    static void remove_tab();
    static void set_treshold(int tr);
    static void raise_level(int l);
    static void lower_level(int l);
private:
    static int t;
    static int tresh;
    static int lvl;
    static fstream file;
};

#endif // LOG_MANAGER_H
