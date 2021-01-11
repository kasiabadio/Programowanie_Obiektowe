#ifndef STOPPER_H_
#define STOPPER_H_
#include <chrono>
#include <iostream>

class Stopper
{
public:
    void start_time_stopper();
    void stop_time_stopper();
    void reset_time_stopper();
    void print_time_stopper();

protected:
    std::chrono::time_point<std::chrono::steady_clock> start_t;
    std::chrono::time_point<std::chrono::steady_clock> stop_t;
    std::chrono::duration<float> duration_time;
};

#endif //STOPPER_H_