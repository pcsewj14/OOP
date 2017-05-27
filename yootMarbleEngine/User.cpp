#include "User.h"
#include "GameDisplay.h"
//#include "ui_User.h"
//#include "showyout.h"
#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <qimage.h>
#include <qpixmap.h>

extern GameDisplay* d;

User::User(int team)
{
	yout = 0;
	this->team = team;
	//������ �ʱ�ȯ��.
	for(int i = 0; i < PIECE_NUM; i++)
	{
		pieces[i] = new Piece;
	}

	sound = new QMediaPlayer;
}

void User::movePiece(int i)
{
	int j;
	if(i < 0 || i > PIECE_NUM)  //i�� ��ȿ�� �������� Ȯ��
	{
		return;
	}

	pieces[i]->move(randomYout);

	//�� ���� ������ ��, �� �� ���� ��ģ��.
	for(j = 0; j < PIECE_NUM; j++)
	{
		if(pieces[i]->getPosition() == pieces[j]->getPosition())
		{
			if((pieces[i] != pieces[j]) && (!pieces[i]->isFinished() && !pieces[j]->isFinished()))
			{
				if(pieces[i]->getNum() + pieces[j]->getNum() <= 3)
				{
					if(pieces[i]->getNum() + pieces[j]->getNum() == 3)
					{
						if(pieces[i]->getNum() == 2)
						{
							unite(i, j);
						}
						else
						{
							unite(j, i);
						}
					}
					else
					{
						unite(i, j);
						if(i > j)
							i = j;
					}
				}
			}
		}
	}

	//���� ���� ���� ����� ��
	for(j = 0; j < PIECE_NUM; j++)
	{
		if(pieces[i]->getPosition() == rival->getPiece(j)->getPosition())
		{
			if(!pieces[i]->isFinished() && !rival->getPiece(j)->isFinished())
			{
				if(pieces[i]->getPosition() != 0)
				{
					rival->resetPiece(j);
					emit caughtPiece(true);
				}
			}
		}
	}
	
	emit thrown();

	if(!pieces[i]->isFinished())
	{
		std::string spaceType = gameBoard->getSpace(pieces[i]->getPosition())->getSpaceType();

		if(spaceType == "Building")
			OnBuildingSpace(i);
		else if(spaceType == "Healing")
			OnHealingSpace(i);
	}
	else
	{
		emit updateDisplay();
	}
}

Piece* User::getPiece(int i)
{
	if(i < 0 || i > PIECE_NUM)  //check if i is valid
	{
		return 0;
	}

	return pieces[i];
}

//�� ���� ��ģ��.
void User::unite(int pieceIndex1, int pieceIndex2)
{
	//ù��° ���� �ִ�ü���� �÷��ְ�, ü���� ��ģ��.
	int resultNum = pieces[pieceIndex1]->getNum() + pieces[pieceIndex2]->getNum();
	pieces[pieceIndex1]->setMaxHP(100*resultNum);
	pieces[pieceIndex1]->get_heal(pieces[pieceIndex2]->getHP());
	pieces[pieceIndex1]->setNum(resultNum);

	//�� ��° ���� ù��° ���� ����Ű�����Ѵ�.
	pieces[pieceIndex2] = pieces[pieceIndex1];

	emit uniteSignal();
}

//���� �׾��� �� ó������ ����������.
void User::resetPiece(int i)
{
	if(pieces[i]->getNum() == 2)
	{
		for(int j = 0; j < PIECE_NUM; j++)
		{
			if(i != j && pieces[i] == pieces[j])
			{
				delete pieces[i];
				pieces[i] = new Piece;
				pieces[j] = new Piece;
				break;
			}
		}
	}
	if(pieces[i]->getNum() == 3)
	{
		delete pieces[i];
		for(int j = 0; j < PIECE_NUM; j++)
		{
			pieces[j] = new Piece;
		}
	}
	else
	{
		delete pieces[i];
		pieces[i] = new Piece;
	}
}

//���� �ǹ� ĭ�� �������� ��
void User::OnBuildingSpace(int i)
{
	current = i;
	int position = pieces[current]->getPosition();
	BuildingSpace* space = dynamic_cast<BuildingSpace*>(gameBoard->getSpace(position));

	bool death_check;
    int owner = space->getTeam();

	//���� ����� �ִ� ĭ�� �ɸ���, ü���� �������� ��´�.
	if(position == 22)
	{
		sound->setMedia(QUrl::fromLocalFile("./sounds/paperAlert.wav"));
		sound->setVolume(FX_VOLUME);
		sound->play();
		//ü���� �𿴴ٴ� �޼����� ����.
		label = new QLabel();
		label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		QImage *info = new QImage();
		QString filename = "./draw/info/reducedLife.png";
		info->load(filename);
		label->setPixmap(QPixmap::fromImage(*info));

		yes = new QPushButton();
		yes->setCursor(Qt::PointingHandCursor);
		QPixmap yeap("./draw/info/confirm.png");
		yes->setIcon(QIcon(yeap));
		yes->setIconSize(yeap.rect().size());
		yes->setFixedSize(yeap.rect().size());
		yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		d->getScene()->addWidget(label);
		d->getScene()->addWidget(yes);
		label->setFixedSize(330, 275);
		label->move(-(label->width()/2), -(label->height()/2));
		yes->move(-(yes->width()/2), 30);

		connect(yes, SIGNAL(clicked()), this, SLOT(PostechConfirm()));
		
		return;
	}

    if(owner == team)  //�ڱ� �ǹ��� �������� �� �ƹ��ϵ� �� �Ͼ��.
	{
		emit updateDisplay();
	}

    else if(owner == !team)  //���� �ǹ��� �������� �� ü���� ��´�.
    {
		death_check = pieces[current]->get_damage(space->getDamagecost());
		d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);
		emit lostHP(space->getDamagecost());
		if(death_check == true)  //���� �׾��� ��
		{
			if(current == 1)
			{
				sound->setMedia(QUrl::fromLocalFile("./sounds/girlDie.mp3"));
			}
			else
			{
				sound->setMedia(QUrl::fromLocalFile("./sounds/boyDie.wav"));
			}
			sound->setVolume(FX_VOLUME);
			sound->play();

			resetPiece(current);

			label = new QLabel();
			label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
			QImage *info = new QImage();
			QString filename = "./draw/info/die.png";
			info->load(filename);
			label->setPixmap(QPixmap::fromImage(*info));

			yes = new QPushButton();
			yes->setCursor(Qt::PointingHandCursor);
			QPixmap yeap("./draw/info/confirm.png");
			yes->setIcon(QIcon(yeap));
			yes->setIconSize(yeap.rect().size());
			yes->setFixedSize(yeap.rect().size());
			yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
			d->getScene()->addWidget(label);
			d->getScene()->addWidget(yes);
			label->setFixedSize(330, 275);
			label->move(-(label->width()/2), -(label->height()/2));
			yes->move(-(yes->width()/2), 30);

			connect(yes, SIGNAL(clicked()), this, SLOT(dieconfirm()));
		}
		else   //���� �� ������, ���� ���� �� �ִ� �ɼ��� �ش�.
		{
			sound->setMedia(QUrl::fromLocalFile("./sounds/paperAlert.wav"));
			sound->setVolume(FX_VOLUME);
			sound->play();

			label = new QLabel();
			label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
			QImage *info = new QImage();
			QString filename = "./draw/info/steal.png";
			info->load(filename);
			label->setPixmap(QPixmap::fromImage(*info));
		
			yes = new QPushButton();
			yes->setCursor(Qt::PointingHandCursor);
			QPixmap yeap("./draw/info/yes.png");
			yes->setIcon(QIcon(yeap));
			yes->setIconSize(yeap.rect().size());
			yes->setFixedSize(yeap.rect().size());
			yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");

			no = new QPushButton();
			no->setCursor(Qt::PointingHandCursor);
			QPixmap nope("./draw/info/no.png");
			no->setIcon(QIcon(nope));
			no->setIconSize(nope.rect().size());
			no->setFixedSize(nope.rect().size());
			no->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");

			d->getScene()->addWidget(label);
			d->getScene()->addWidget(yes);
			d->getScene()->addWidget(no);

			label->setFixedSize(330, 275);
			label->move(-(label->width()/2), -(label->height()/2));
			yes->move(-35 - 275/4, 30);
			no->move(-20 + 275/4, 30);

			connect(yes, SIGNAL(clicked()), this, SLOT(stealSpace()));
			connect(no, SIGNAL(clicked()), this, SLOT(donothing()));
		}
    }
    else  //�ǹ��� ������ ���� ��, �� �� �ִ� �ɼ��� �ش�.
    {
		sound->setMedia(QUrl::fromLocalFile("./sounds/paperAlert.wav"));
		sound->setVolume(FX_VOLUME);
		sound->play();

		label = new QLabel();
		label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		QImage *info = new QImage();
		QString filename = "./draw/info/buy.png";
		info->load(filename);
		label->setPixmap(QPixmap::fromImage(*info));
		
		yes = new QPushButton();
		yes->setCursor(Qt::PointingHandCursor);
		QPixmap yeap("./draw/info/yes.png");
		yes->setIcon(QIcon(yeap));
		yes->setIconSize(yeap.rect().size());
		yes->setFixedSize(yeap.rect().size());
		yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");

		no = new QPushButton();
		no->setCursor(Qt::PointingHandCursor);
		QPixmap nope("./draw/info/no.png");
		no->setIcon(QIcon(nope));
		no->setIconSize(nope.rect().size());
		no->setFixedSize(nope.rect().size());
		no->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		label->setFixedSize(330, 275);
		label->move(-(label->width()/2), -(label->height()/2));
		yes->move(-35 - 275/4, 30);
		no->move(-20 + 275/4, 30);
		
		d->getScene()->addWidget(label);
		d->getScene()->addWidget(yes);
		d->getScene()->addWidget(no);

		connect(yes, SIGNAL(clicked()), this, SLOT(buySpace()));
		connect(no, SIGNAL(clicked()), this, SLOT(donothing()));
    }
}

//���� ü��ȸ��ĭ�� �������� ��
void User::OnHealingSpace(int i)
{
	current = i;
	int position = pieces[current]->getPosition();
	HealingSpace* space = dynamic_cast<HealingSpace*>(gameBoard->getSpace(position));

	//���� Ȳ�ݿ��� ĭ�� �������� ��
	if(position == 6 || position == 16)
	{
		sound->setMedia(QUrl::fromLocalFile("./sounds/onGoldenKey.mp3"));
		sound->setVolume(FX_VOLUME);
		sound->play();
		label = new QLabel();
		label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		QImage *info = new QImage();
		QString filename = "./draw/info/goldenKey.png";
		info->load(filename);
		label->setPixmap(QPixmap::fromImage(*info));

		yes = new QPushButton();
		yes->setCursor(Qt::PointingHandCursor);
		QPixmap yeap("./draw/info/confirm.png");
		yes->setIcon(QIcon(yeap));
		yes->setIconSize(yeap.rect().size());
		yes->setFixedSize(yeap.rect().size());
		yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		d->getScene()->addWidget(label);
		d->getScene()->addWidget(yes);
		label->setFixedSize(330, 275);
		label->move(-(label->width()/2), -(label->height()/2));
		yes->move(-(yes->width()/2), 30);

		//Ȳ�ݿ��� ȿ���� �����Ѵ�.
		connect(yes, SIGNAL(clicked()), this, SLOT(keyEffect()));
		return;
	}

	sound->setMedia(QUrl::fromLocalFile("./sounds/paperAlert.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();

	//ü���� ȸ���ϰ�, �޼����� ����.
	pieces[current]->get_heal(space->getheal());
	d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);
	
	label = new QLabel();
	label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	QImage *info = new QImage();
	QString filename;
	if(position == 5)
		filename = "./draw/info/10healed.png";
	else
		filename = "./draw/info/30healed.png";
	info->load(filename);
	label->setPixmap(QPixmap::fromImage(*info));

	yes = new QPushButton();
	yes->setCursor(Qt::PointingHandCursor);
	QPixmap yeap("./draw/info/confirm.png");
	yes->setIcon(QIcon(yeap));
	yes->setIconSize(yeap.rect().size());
	yes->setFixedSize(yeap.rect().size());
	yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
	label->setFixedSize(330, 275);
	label->move(-(label->width()/2), -(label->height()/2));
	yes->move(-(yes->width()/2), 30);
	
	d->getScene()->addWidget(label);
	d->getScene()->addWidget(yes);
	
	connect(yes, SIGNAL(clicked()), this, SLOT(confirm()));
}

//�� ������ �� ���� ���¸�, true�� ��ȯ�Ѵ�.
bool User::win()
{
   bool win = true;
   for(int i = 0; i < PIECE_NUM; i++)
   {
	   win &= pieces[i]->isFinished();
   }

   return win;
}

//�ǹ��� �� �� �θ��� �Լ�
void User::buySpace()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	disconnect(no, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();
	no->close();

	int position = pieces[current]->getPosition();
	BuildingSpace* space = dynamic_cast<BuildingSpace*>(gameBoard->getSpace(position));
    if(pieces[current]->getHP() > space->getBuycost())
    {
		sound->setMedia(QUrl::fromLocalFile("./sounds/getBuilding.mp3"));
		sound->setVolume(FX_VOLUME);
		sound->play();
		
		QPixmap region("./draw/update" + QString::number(team) + "/" + QString::number(position) + ".png");
		d->getImage(position)->setIcon(QIcon(region));
		d->getScene()->addWidget(d->getImage(position));

		pieces[current]->get_damage(space->getBuycost());
        d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);
		space->setTeam(team);
		emit updateDisplay();
    }
	else
	{
		label = new QLabel();
		label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		QImage *info = new QImage();
		QString filename = "./draw/info/can'tBuy.png";
		info->load(filename);
		label->setPixmap(QPixmap::fromImage(*info));

		yes = new QPushButton();
		yes->setCursor(Qt::PointingHandCursor);
		QPixmap yeap("./draw/info/confirm.png");
		yes->setIcon(QIcon(yeap));
		yes->setIconSize(yeap.rect().size());
		yes->setFixedSize(yeap.rect().size());
		yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		d->getScene()->addWidget(label);
		d->getScene()->addWidget(yes);
		label->setFixedSize(330, 275);
		label->move(-(label->width()/2), -(label->height()/2));
		yes->move(-(yes->width()/2), 30);

		connect(yes, SIGNAL(clicked()), this, SLOT(confirm()));
	}
}

//�ǹ��� ���� �� �θ��� �Լ�
void User::stealSpace()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	disconnect(no, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();
	no->close();

	int position = pieces[current]->getPosition();
	BuildingSpace* space = dynamic_cast<BuildingSpace*>(gameBoard->getSpace(position));
    if(pieces[current]->getHP() > space->getStealcost())
    {
		sound->setMedia(QUrl::fromLocalFile("./sounds/getBuilding.mp3"));
		sound->setVolume(FX_VOLUME);
		sound->play();

		disconnect(yes, SIGNAL(clicked()), 0, 0);
		disconnect(no, SIGNAL(clicked()), 0, 0);
		yes->close();
		no->close();

		QPixmap region("./draw/update" + QString::number(team) + "/" + QString::number(position) + ".png");
		d->getImage(position)->setIcon(QIcon(region));
		d->getScene()->addWidget(d->getImage(position));

        pieces[current]->get_damage(space->getStealcost());
        d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);
		space->setTeam(team);
		emit updateDisplay();
    }
	else  //ü���� �����ؼ� �ǹ��� �� ���� ���
	{
		label = new QLabel();
		label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		QImage *info = new QImage();
		QString filename = "./draw/info/can'tSteal.png";
		info->load(filename);
		label->setPixmap(QPixmap::fromImage(*info));

		yes = new QPushButton();
		yes->setCursor(Qt::PointingHandCursor);
		QPixmap yeap("./draw/info/confirm.png");
		yes->setIcon(QIcon(yeap));
		yes->setIconSize(yeap.rect().size());
		yes->setFixedSize(yeap.rect().size());
		yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		d->getScene()->addWidget(label);
		d->getScene()->addWidget(yes);
		label->setFixedSize(330, 275);
		label->move(-(label->width()/2), -(label->height()/2));
		yes->move(-(yes->width()/2), 30);

		connect(yes, SIGNAL(clicked()), this, SLOT(confirm()));
	}
}

//�ƹ��� �׼��� ������ �ʰ�, ���� �������� �ѱ��.
void User::donothing()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	disconnect(no, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();
	no->close();
	//emit turnEnd();
	emit updateDisplay();
}

void User::confirm()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();
	//emit turnEnd();
	emit updateDisplay();
}

void User::confirm1()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	yes->close();

	emit updateDisplay();
}

//Ȳ�ݿ��� ȿ��
void User::keyEffect()
{
	bool death_check = false;
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();

	yes = new QPushButton();
	yes->setFixedSize(1200, 730);
	yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	yes->move(-H_LIMIT, -V_LIMIT);

	srand(time(0));
	int effectNum = rand() % 14;
	if(effectNum < 2)
	{
		QPixmap pix("./draw/info/0.png");
		yes->setIconSize(pix.rect().size());
		yes->setIcon(QIcon(pix));
		d->getScene()->addWidget(yes);

		death_check = hackathon();
	}
	else if(effectNum < 4)
	{
		QPixmap pix("./draw/info/1.png");
		yes->setIconSize(pix.rect().size());
		yes->setIcon(QIcon(pix));
		d->getScene()->addWidget(yes);

		festival();
	}
	else if(effectNum < 6)
	{
		QPixmap pix("./draw/info/2.png");
		yes->setIconSize(pix.rect().size());
		yes->setIcon(QIcon(pix));
		d->getScene()->addWidget(yes);

		RAtalk();
	}
	else if(effectNum < 10)
	{
		QPixmap pix("./draw/info/3.png");
		yes->setIconSize(pix.rect().size());
		yes->setIcon(QIcon(pix));
		d->getScene()->addWidget(yes);

		lostMemory();
	}
	else if(effectNum < 13)
	{
		QPixmap pix("./draw/info/4.png");
		yes->setIconSize(pix.rect().size());
		yes->setIcon(QIcon(pix));
		d->getScene()->addWidget(yes);

		//rival->resetPiece(0);
		postechKaistScienceWar();
	}
	else if(effectNum == 13)
	{
		QPixmap pix("./draw/info/5.png");
		yes->setIconSize(pix.rect().size());
		yes->setIcon(QIcon(pix));
		d->getScene()->addWidget(yes);

		phoenix();
	}

	if(death_check == false)
		connect(yes, SIGNAL(clicked()), this, SLOT(confirm1()));
	
	else
		connect(yes, SIGNAL(clicked()), this, SLOT(HackathonDie()));
	
	return;
}

//���� �׾��� �� �޼����� ����.
void User::dieconfirm()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();
	
	emit die(false);
	emit updateDisplay();
}

User::~User()
{
}

//////Ȳ�ݿ��� ȿ��/////

//���� ü���� ��� ȿ��
bool User::hackathon()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/hackathon.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();

	srand(time(0));
	int damage = 50;
	bool death_check = pieces[current]->get_damage(damage * pieces[current]->getNum());
	d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);
	//emit lostHP(randomDamage);
	
	return death_check;
}

//���� ü���� ȸ���Ѵ�.
void User::RAtalk()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/RAtalk.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	pieces[current]->get_heal(60);
	d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);
}

//�� ���� ���� ü���� �� �ø���.
void User::festival()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/festival.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	for(int i = 0; i < PIECE_NUM; i++)
	{
		pieces[i]->get_heal(40);
		d->setHPText(i, team, pieces[i]->getHP(), pieces[i]->getNum()*100);
	}
}

//��� ���� ������ ��ҷ� ������.
void User::lostMemory()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/lostMemory.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	srand(time(0));
	int randomPosition;
	bool canChange = false;
	for(int i = 0; i < PIECE_NUM; i++)
	{
		canChange = false;
		randomPosition = rand() % 28 + 1;
		while(!canChange)
		{
			canChange = true;
			for(int i = 0; i < PIECE_NUM; i++)
			{
				if(pieces[i]->getPosition() == randomPosition && !pieces[i]->isFinished())
				{
					canChange = false;
				}
			}
			for(int i = 0; i < PIECE_NUM; i++)
			{
				if(rival->getPiece(i)->getPosition() == randomPosition && !rival->getPiece(i)->isFinished())
				{
					canChange = false;
				}
			}
			if(!canChange)
			{
				randomPosition = rand() % 28 + 1;
			}
		}
		pieces[i]->setPosition(randomPosition);
	}

	for(int i = 0; i < PIECE_NUM; i++)
	{
		canChange = false;
		randomPosition = rand() % 28 + 1;
		while(!canChange)
		{
			canChange = true;
			for(int i = 0; i < PIECE_NUM; i++)
			{
				if(pieces[i]->getPosition() == randomPosition && !pieces[i]->isFinished())
				{
					canChange = false;
				}
			}
			for(int i = 0; i < PIECE_NUM; i++)
			{
				if(rival->getPiece(i)->getPosition() == randomPosition && !rival->getPiece(i)->isFinished())
				{
					canChange = false;
				}
			}
			if(!canChange)
			{
				randomPosition = rand() % 28 + 1;
			}
		}
		rival->getPiece(i)->setPosition(randomPosition);
	}
	emit thrown();
}

//���� �� �ϳ��� ���������� ������.
void User::postechKaistScienceWar()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/poKaBattle.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	srand(time(0));
	int randomIndex = rand() % 3;
	bool valid = false;
	bool canReset = false;
	for(int i = 0; i < PIECE_NUM; i++)
	{
		if(!rival->getPiece(i)->isFinished() && rival->getPiece(i)->getPosition() > 0)
		{
			canReset = true;
		}
	}

	if(!canReset)
	{
		return;
	}

	while(!valid)
	{
		if(!rival->getPiece(randomIndex)->isFinished() && rival->getPiece(randomIndex)->getPosition() > 0)
		{
			valid = true;
		}
		else
		{
			randomIndex = rand() % 3;
		}
	}

	rival->resetPiece(randomIndex);
	emit caughtPiece(false);
	//emit thrown();
}

//���� ���� �¸��Ѵ�.
void User::phoenix()
{
	bgm->pause();
	sound->setMedia(QUrl::fromLocalFile("./sounds/pheonix.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	for(int i = 0; i < PIECE_NUM; i++)
	{
		pieces[i]->finish();
	}
}

//��ī�� ������ ���� �׾��� �� �޼����� ����.
void User::HackathonDie()
{
	if(current == 1)
	{
		sound->setMedia(QUrl::fromLocalFile("./sounds/girlDie.mp3"));
	}	
	else
	{
		sound->setMedia(QUrl::fromLocalFile("./sounds/boyDie.wav"));
	}
	sound->setVolume(FX_VOLUME);
	sound->play();
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();

	resetPiece(current);

	label = new QLabel();
	label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	QImage *info = new QImage();
	QString filename = "./draw/info/die.png";
	info->load(filename);
	label->setPixmap(QPixmap::fromImage(*info));

	yes = new QPushButton();
	yes->setCursor(Qt::PointingHandCursor);
	QPixmap yeap("./draw/info/confirm.png");
	yes->setIcon(QIcon(yeap));
	yes->setIconSize(yeap.rect().size());
	yes->setFixedSize(yeap.rect().size());
	yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	
	d->getScene()->addWidget(label);
	d->getScene()->addWidget(yes);
	label->setFixedSize(330, 275);
	label->move(-(label->width()/2), -(label->height()/2));
	yes->move(-(yes->width()/2), 30);

	connect(yes, SIGNAL(clicked()), this, SLOT(dieconfirm()));
}

void User::PostechConfirm()
{
	disconnect(yes, SIGNAL(clicked()), 0, 0);
	label->close();
	yes->close();

	srand(time(0));
	int randomDamage = rand() %  50 + 30;
	bool death_check = pieces[current]->get_damage(randomDamage * pieces[current]->getNum());
	d->setHPText(current, team, pieces[current]->getHP(), pieces[current]->getNum()*100);

	//���� �׾��� ��, ó������ ����������, �޼����� ����.
	if(death_check == true)
	{
		if(current == 1)
		{
			sound->setMedia(QUrl::fromLocalFile("./sounds/girlDie.mp3"));
		}	
		else
		{
			sound->setMedia(QUrl::fromLocalFile("./sounds/boyDie.wav"));
		}
		sound->setVolume(FX_VOLUME);
		sound->play();
		resetPiece(current);

		label = new QLabel();
		label->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		QImage *info = new QImage();
		QString filename = "./draw/info/die.png";
		info->load(filename);
		label->setPixmap(QPixmap::fromImage(*info));

		yes = new QPushButton();
		yes->setCursor(Qt::PointingHandCursor);
		QPixmap yeap("./draw/info/confirm.png");
		yes->setIcon(QIcon(yeap));
		yes->setIconSize(yeap.rect().size());
		yes->setFixedSize(yeap.rect().size());
		yes->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		d->getScene()->addWidget(label);
		d->getScene()->addWidget(yes);
		label->setFixedSize(330, 275);
		label->move(-(label->width()/2), -(label->height()/2));
		yes->move(-(yes->width()/2), 30);

		connect(yes, SIGNAL(clicked()), this, SLOT(dieconfirm()));
	}
	else
		emit updateDisplay();
}