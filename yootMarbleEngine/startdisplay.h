#ifndef STARTDISPLAY_H
#define STARTDISPLAY_H

#include <QGraphicsScene>
#include <QPushButton>

//���� ����ȭ���� ��Ÿ���� QGraphicsScene
class StartDisplay : public QGraphicsScene
{
    Q_OBJECT
private:
    QPushButton *game_start, *game_explain, *game_exit;
public:
    StartDisplay();
	QPushButton* getStartButton(){return game_start;}
	QPushButton* getExplainButton(){return game_explain;}
	QPushButton* getExitButton(){return game_exit;}
};

#endif // STARTDISPLAY

