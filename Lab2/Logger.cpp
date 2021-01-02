#include "Logger.h"

Logger::Logger():
    znaki{nullptr},
    can_log{true}
{}

Logger::Logger(bool _debug):
    znaki{nullptr},
    can_log(_debug)
{}

Logger::~Logger()
{
    delete this->znaki;
}

void Logger::log(std::string _znaki){
    time_t t;
    if(can_log){
        printf("%s %s\n", ctime(&t), _znaki);
    }
}
