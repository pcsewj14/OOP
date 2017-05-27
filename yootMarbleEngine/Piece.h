#ifndef PIECE_H
#define PIECE_H

/*
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPushButton>
*/

class Piece //: public QPushButton
{
private:
    int HP;
	int maxHP;
	int position;
	bool finished;
	//int team;
	int num;  //how many pieces this piece is.

public:
    //Piece(int HP, int position, int team, int num);
	Piece();
    //int move(int move_num);
	void move(int move_num);
    bool get_damage(int damage);
    void get_heal(int heal);
    void finish();
    void setMaxHP(int maxHP);
    void setPosition(int position);
	bool isFinished(){ return finished; };
    int getHP();
    int getPosition();
	void setNum(int num){ this->num = num; };
	int getNum(){ return num; };

    //int getTeam();
};

#endif // PIECE_H