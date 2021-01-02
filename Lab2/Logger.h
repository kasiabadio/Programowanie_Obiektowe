#ifndef LOGGER_H_
#define LOGGER_H_
#include <string>
#include <ctime>
#include <iostream>

class Logger{
public:
    Logger();
    Logger(bool _debug);
    void log(std::string _znaki);
    ~Logger();
    

protected:
    std::string *znaki;
    bool can_log;
};



#endif //LOGGER_H_