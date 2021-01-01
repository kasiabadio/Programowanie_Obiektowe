#ifndef WEZEL_H_
#define WEZEL_H_
#include <iostream>
#include <memory>

class Wezel{
public:
    Wezel();
    ~Wezel();
    std::shared_ptr<Wezel> next;
    std::weak_ptr<Wezel> next_weak;
};


#endif // WEZEL_H_