#include "Board.h"

//보드의 칸을 초기화한다.
Board::Board()
{
	for(int i = 0; i < SPACE_NUM; i++)
	{
		BoardSpaces[i] = new Space;
	}

    BoardSpaces[0] = new HealingSpace(0);
    BoardSpaces[0]->setExplainString("Healing!!");

	for(int i=1; i<5; i++)
		BoardSpaces[i] = new BuildingSpace(40, 10, 10);
	for(int i=6; i<10; i++)
		BoardSpaces[i] = new BuildingSpace(40, 20, 20);
	for(int i=11; i<15; i++)
		BoardSpaces[i] = new BuildingSpace(50, 30, 30);
	for(int i=16; i<20; i++)
		BoardSpaces[i] = new BuildingSpace(70, 50, 10);
	
	BoardSpaces[5] = new HealingSpace(10);
	BoardSpaces[10] = new HealingSpace(30);
	BoardSpaces[6] = new HealingSpace(0);   //golden key
	BoardSpaces[15] = new HealingSpace(30);
	BoardSpaces[16] = new HealingSpace(0);  //golden key
    BoardSpaces[20] = new BuildingSpace(50, 40, 10);
    BoardSpaces[21] = new BuildingSpace(50, 40, 10);
    BoardSpaces[22] = new BuildingSpace(0, 0, 0);  //changed
    BoardSpaces[23] = new BuildingSpace(60, 40, 10);
    BoardSpaces[24] = new BuildingSpace(60, 40, 10);
    BoardSpaces[25] = new BuildingSpace(70, 40, 10);
    BoardSpaces[26] = new BuildingSpace(70, 40, 10);
    BoardSpaces[27] = new BuildingSpace(90, 70, 0);
    BoardSpaces[28] = new BuildingSpace(90, 70, 0);
}

Board::~Board()
{
    for(int i = 0; i < SPACE_NUM; i++)
    {
        delete BoardSpaces[i];
    }
}

Space *Board::getSpace(int position)
{
	if(position > SPACE_NUM || position < 0)
	{
		return 0;
	}
    return BoardSpaces[position];
}
