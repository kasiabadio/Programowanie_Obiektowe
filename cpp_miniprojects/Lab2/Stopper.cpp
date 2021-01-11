#include "Stopper.h"

void Stopper::start_time_stopper()
{
    start_t = std::chrono::steady_clock::now();
}

void Stopper::stop_time_stopper()
{
    stop_t = std::chrono::steady_clock::now();
    duration_time += stop_t - start_t;
}

void Stopper::reset_time_stopper()
{
    start_t = std::chrono::steady_clock::now();
}

void Stopper::print_time_stopper()
{
    std::cout << "Calkowity czas wywolywania funkcji na tym obiekcie: " << duration_time.count() << std::endl;
}
