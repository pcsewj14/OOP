//#include "yootmarbleengine.h"
#include "GameDisplay.h"
#include <QtWidgets/QApplication>
#include <qmediaplaylist.h>

#include <youtNumber.h>

int randomYout = 0;
Board *gameBoard;
GameDisplay *d;
QMediaPlayer* bgm;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*
	yootMarbleEngine w;
	w.show();
	*/
	QMediaPlaylist* bgmLoop = new QMediaPlaylist;
	bgmLoop->addMedia(QUrl::fromLocalFile("./sounds/bgm.mp3"));
	bgmLoop->setPlaybackMode(QMediaPlaylist::Loop);
	bgm = new QMediaPlayer;
	bgm->setPlaylist(bgmLoop);
	bgm->setVolume(50);
	bgm->play();
	
	d = new GameDisplay();
	d->resize(1200, 730);  //set size of screen
	d->show();
	//d.startGame();

	return a.exec();
}
