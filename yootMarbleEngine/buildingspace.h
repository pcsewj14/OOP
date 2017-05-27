#ifndef BUILDINGSPACE_H
#define BUILDINGSPACE_H

#include "Space.h"
#include "Piece.h"

class BuildingSpace : public Space
{
private:
    std::string explainString;
    //Player Owner;
    int team;
    int buy_cost, damage_cost, steal_cost;

public:
    BuildingSpace(int damage_cost, int buy_cost, int steal_cost);
    void setExplainString(const std::string s){ explainString = s; }
    void buy();
    void take(Piece* p);
    void damage(Piece* p);
    void setTeam(int team){this->team = team;}
    int getTeam(){return team;}
    int getBuycost(){return buy_cost;}
    int getDamagecost(){return damage_cost;}
    int getStealcost(){return steal_cost;}
};

#endif // BUILDINGSPACE_H

