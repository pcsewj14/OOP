#ifndef HEALINGSPACE_H
#define HEALINGSPACE_H

#include "space.h"

class HealingSpace : public Space
{
private:
    int heal;
    std::string explainstring;

public:
    HealingSpace(int heal);
    void setheal(int heal);
    int getheal();
    void setExplainString(const std::string s);
    //void explain();
};

#endif // HEALINGSPACE_H

