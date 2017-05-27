#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H

#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qsignalmapper.h>
#include <qglobal.h>
#include <qfont.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qprogressbar.h>

#include <qurl.h>
#include <qmediaplayer.h>
#include <qsound.h>
#include <qmediaplaylist.h>

#include <Board.h>
#include <User.h>
#include <youtNumber.h>

#include <ctime>

#define SPACE_NUM 29  //ĭ�� ����
#define H_LIMIT 600   //ȭ�� ���� ũ���� ��
#define V_LIMIT 365   //ȭ�� ���� ũ���� ��
#define BUTTON_WIDTH 70  //���� �ʺ�
#define BUTTON_HEIGHT 80  //���� ����

class GameDisplay : public QGraphicsView
{
	Q_OBJECT

private:
	QGraphicsScene *scene;
	QGraphicsScene *explain;	//���Ӽ���â
	QPushButton* throwButton;
	QPushButton* image[29];
	QLabel* building;
	QLabel* back;
	QImage* exp[19];

	User* player1;
	User* player2;
	QPushButton* player1Pieces[PIECE_NUM];
	QPushButton* player2Pieces[PIECE_NUM];
	QPushButton* resetButton;

	QSignalMapper* signalMapper1;
	QSignalMapper* signalMapper2;
	QSignalMapper* signalMapper3;

	bool turn;     //���� ������ �Ǻ��ϱ� ���ؼ� ����.
	bool caught;   //���� �������� �Ǻ��ϱ� ���ؼ� ����..
	int current;

	bool player1Finished[PIECE_NUM];
	bool player2Finished[PIECE_NUM];

	//used for debugging
	QLabel* turnLabel;
	QLabel* youtLabel;
	QProgressBar *HP1[3], *HP2[3];
	QLabel *HP1Text[3], *HP2Text[3];

	int piece1_num;
	int piece2_num;

	QMediaPlayer* sound;

public:
	GameDisplay(QWidget *parent = 0);
	~GameDisplay();
	void setSpaces();
	void startGame();
	void showTurn();
	void throwYout();
	void initializeGame();

	void sceneAddWidgets();

	QGraphicsScene* getScene(){return scene;}
	void setHPText(int i, int team, int hp, int maxhp);
	QPushButton* getImage(int position) { return image[position]; }

private slots:
	void selectAndMove();
	void updateGame();
	void newGame();
	void unitePieces();
	void movePieces();
	void resetPieces(bool isCaught);
	void stealHP(int damage);
	void explainSpace(int position);

	void Piece1_num1() { piece1_num = 0; }
	void Piece1_num2() { piece1_num = 1; }
	void Piece1_num3() { piece1_num = 2; }

	void Piece2_num1() { piece2_num = 0; }
	void Piece2_num2() { piece2_num = 1; }
	void Piece2_num3() { piece2_num = 2; }

    void StartGame();
    void ExplainGame();
    void ExitGame();

	void showPre();
	void showNext();
};
#endif // GAMEDISPLAY_H
