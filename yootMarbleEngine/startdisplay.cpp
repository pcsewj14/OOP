#include "startdisplay.h"
//#include "GameDisplay.h"

#include <QImage>
#include <QPixmap>
#include <QIcon>
#include <QPalette>

StartDisplay::StartDisplay()
{
    setSceneRect(0, 0, 1300, 660);
    QImage *image = new QImage(":/images/start_page.png");
    *image = image->scaled(1300, 660);
    QBrush *background = new QBrush(*image);
    setBackgroundBrush(*background);
	
    QPixmap pixmap1(":/images/start_button.png");
    game_start = new QPushButton();
	game_start->setCursor(Qt::PointingHandCursor);
    game_start->setIcon(QIcon(pixmap1));
    game_start->setIconSize(pixmap1.rect().size());
    game_start->setFixedSize(pixmap1.rect().size());
    game_start->setFlat(true);
    game_start->setAutoFillBackground(true);
    game_start->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");

    QPixmap pixmap2(":/images/explain_button.png");
    game_explain = new QPushButton();
	game_explain->setCursor(Qt::PointingHandCursor);
    game_explain->setIcon(QIcon(pixmap2));
    game_explain->setIconSize(pixmap2.rect().size());
    game_explain->setFixedSize(pixmap2.rect().size());
    game_explain->setFlat(true);
    game_explain->setAutoFillBackground(true);
    game_explain->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");

    QPixmap pixmap3(":/images/exit_button.png");
    game_exit = new QPushButton();
	game_exit->setCursor(Qt::PointingHandCursor);
    game_exit->setIcon(QIcon(pixmap3));
    game_exit->setIconSize(pixmap3.rect().size());
    game_exit->setFixedSize(pixmap3.rect().size());
    game_exit->setFlat(true);
    game_exit->setAutoFillBackground(true);
    game_exit->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");

    addWidget(game_start);
    addWidget(game_explain);
    addWidget(game_exit);
    game_start->move(650 - (game_start->width()/2), 250);
    game_explain->move(650 - (game_explain->width()/2), 370);
    game_exit->move(650 - (game_exit->width()/2), 490);

    connect(game_start, SIGNAL(clicked(bool)), this, SLOT(StartGame()));
    connect(game_exit, SIGNAL(clicked(bool)), this, SLOT(ExitGame()));
}