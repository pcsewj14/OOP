#ifndef SPACE_H
#define SPACE_H

//#include<iostream>
#include <iostream>

class Space
{
private:
    //Space* next;
    std::string spaceType;
    std::string name;
    bool PieceOn;
	int xPosition;
	int yPosition;

public:
    //virtual ~Space(){}
    //bool hasPiece();
    //void setNext(Space* next){ this->next = next; };
	Space(){};
    void setName(std::string name){ this->name = name; }
    void setSpaceType(const std::string& type){ spaceType = type; }
    std::string getSpaceType(){ return spaceType; }
	void setPosition(int x, int y){ xPosition = x; yPosition = y; };
	int getXPosition(){ return xPosition; };
	int getYPosition(){ return yPosition; };
    virtual void setExplainString(const std::string s){ return; }
    virtual void explain(){ return; }

    //Space* getNext(){ return next; };
    std::string getName(){ return name; }
};

#endif // SPACE_H

