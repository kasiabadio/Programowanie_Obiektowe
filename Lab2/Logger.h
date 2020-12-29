#ifndef LOGGER_H_
#define LOGGER_H_
#include <string>
#include <time.h>

class Logger{
public:
    Logger();
    void log(std::string _znaki);
    ~Logger();

protected:
    std::string *znaki;
};



#endif //LOGGER_H_