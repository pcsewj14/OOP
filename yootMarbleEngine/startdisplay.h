#ifndef STARTDISPLAY_H
#define STARTDISPLAY_H

#include <QGraphicsScene>
#include <QPushButton>

//게임 시작화면을 나타내는 QGraphicsScene
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

