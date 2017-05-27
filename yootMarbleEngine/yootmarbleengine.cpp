/*
#include "yootmarbleengine.h"

yootMarbleEngine::yootMarbleEngine(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	QPushButton* button1 = new QPushButton();
	button1->setText("yoot");
	scene = new QGraphicsScene;
	scene->addText("hello");
	button1->move(1000,-50);
	scene->addWidget(button1);
	button1->setText("yo");

	view = new QGraphicsView(scene);
	view->show();
}

yootMarbleEngine::~yootMarbleEngine()
{

}
*/