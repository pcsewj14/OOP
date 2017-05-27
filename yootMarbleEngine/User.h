#ifndef USER_H
#define USER_H

//#include <QObject>
#include <qobject.h>
#include <Piece.h>
#include "youtNumber.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qmediaplayer.h>
#include <qurl.h>

//#define PIECE_NUM 1
#define PIECE_NUM 3

class User : public QObject
{
    Q_OBJECT

private:
    int yout;
	int team;
	int current;
	Piece* pieces[PIECE_NUM];
	User* rival;

	QLabel *label;
	QPushButton *yes, *no;

	QMediaPlayer* sound;

public:
    explicit User(int team);
    ~User();
	 Piece* getPiece(int i);
	 void unite(int pieceIndex1, int pieceIndex2);
	 void setRival(User* rival){ this->rival = rival; };
	 void resetPiece(int i);
	 void OnBuildingSpace(int i);
	 void OnHealingSpace(int i);

	 //황금열쇠 효과/////
	 bool hackathon();
	 void festival();
	 void RAtalk();
	 void lostMemory();
	 void postechKaistScienceWar();
	 void phoenix();

	 bool win();

	 QMediaPlayer* getSound(){ return sound; };

signals:
	void thrown();
	void uniteSignal();
	void caughtPiece(bool isCaught);
	void lostHP(int damage);
	//void turnEnd();
	void die(bool isCaught);
	void updateDisplay();

	void debugSignal();

private slots:
	void movePiece(int i);
	void buySpace();
	void stealSpace();
	void donothing();
	void confirm();
	void confirm1();
	void dieconfirm();
	void keyEffect();
	void HackathonDie();
	void PostechConfirm();
};

#endif // USER_H