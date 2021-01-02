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
    time_t t = time(0);
    char* date_time = ctime(&t);
    if(can_log){
        std::cout << std::endl << _znaki << " " << date_time;
    }
}
