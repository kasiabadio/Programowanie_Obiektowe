#include "Logger.h"

Logger::Logger():
    znaki{nullptr}
{}


void Logger::log(std::string _znaki){
    time_t t;
    printf("%s %s\n", ctime(&t), _znaki);
}