#ifndef BOARD_H
#define BOARD_H

#include<iostream>

#include "Piece.h"
#include "Space.h"
#include "buildingspace.h"
#include "healingspace.h"

#define SPACE_NUM 29
//#define PIECE_NUM 1

class Board
{
private:
    Space* BoardSpaces[SPACE_NUM];
    //Piece* playerPieces[PIECE_NUM];

public:
    Board();
    ~Board();


	/*
    void move(int index, int moveNum);
    void update();
    void draw();
	*/
    Space* getSpace(int position);
};

#endif // BOARD_H

