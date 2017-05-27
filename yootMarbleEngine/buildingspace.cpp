#include "BuildingSpace.h"

BuildingSpace::BuildingSpace(int damage_cost, int buy_cost, int steal_cost) : Space()
{
    setSpaceType("Building");
	this->buy_cost = buy_cost;
	this->damage_cost = damage_cost;
	this->steal_cost = steal_cost;
	team = -1;
}
