#include "GameDisplay.h"
#include "startdisplay.h"

GameDisplay::GameDisplay(QWidget *parent)
	: QGraphicsView(parent)
{
	initializeGame();
}

void GameDisplay::initializeGame()
{
	bgm->setVolume(50);
	bgm->play();

	sound = new QMediaPlayer;
	gameBoard = new Board;

	player1 = new User(0);
	player2 = new User(1);

	for(int i = 0; i < PIECE_NUM; i++)   //���� �ش��ϴ� QPushButton�� �����.
	{
		player1Pieces[i] = new QPushButton();
		player1Pieces[i]->setCursor(Qt::PointingHandCursor);
		player1Pieces[i]->setIcon(QIcon("./characters/char1" + QString::number(i+1) + ".png"));
		player1Pieces[i]->resize(BUTTON_WIDTH, BUTTON_HEIGHT);
		player1Pieces[i]->setIconSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
		player1Pieces[i]->move(H_LIMIT - 270 + 70*i, V_LIMIT - 150);   //fixedHere
		player1Pieces[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");

		player2Pieces[i] = new QPushButton();
		player2Pieces[i]->setCursor(Qt::PointingHandCursor);
		player2Pieces[i]->setIcon(QIcon("./characters/char2" + QString::number(i+1) + ".png"));
		player2Pieces[i]->setIconSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
		player2Pieces[i]->resize(BUTTON_WIDTH, BUTTON_HEIGHT);
		player2Pieces[i]->move(H_LIMIT - 270 + 70*i, V_LIMIT - 100);    //fixedHere
		player2Pieces[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");
	}

	player1->setRival(player2);     //player���� ������ �������� ������ �� �ְ� �Ѵ�.
	player2->setRival(player1);

	//���� ������ ��Ÿ�� �� ���� QLabel�� �����Ѵ�.
	turnLabel = new QLabel;
	turnLabel->move(H_LIMIT - 270, -V_LIMIT + 100);
	turnLabel->resize(150, 30);
	turnLabel->setText("Player1's turn!!");   //player1�� ���� �����Ѵ�.
	QFont turnLabelFont("Arial", 15, QFont::Bold);
	turnLabel->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	turnLabel->setFont(turnLabelFont);
	
	//���� ������ �� ���� ���ڸ� ǥ���ϴ� QLabel�� �����.
	youtLabel = new QLabel;
	youtLabel->move(H_LIMIT - 115, -V_LIMIT + 100);
	youtLabel->resize(100, 30);
	QFont youtLabelFont("Times", 20);
	youtLabel->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	youtLabel->setFont(youtLabelFont);

	//ü�¹ٿ� �ش��ϴ� QProgressBar�� �����, �˸��� ��ġ�� ���´�.
	QFont HPfont("Times", 8);
	for(int i=0; i<3; i++)
	{
		HP1[i] = new QProgressBar();
		HP1[i]->setFixedSize(70, 15);
		HP1[i]->setTextVisible(false);
		HP1[i]->setValue(100);
		HP1[i]->move(player1Pieces[i]->x(), player1Pieces[i]->y()-10);
		HP1Text[i] = new QLabel();
		HP1Text[i]->setFixedSize(HP1[i]->width(), HP1[i]->height());
		HP1Text[i]->setText(QString::number(100) + "/" + QString::number(100));
		HP1Text[i]->setAlignment(Qt::AlignHCenter);
		HP1Text[i]->setAlignment(Qt::AlignCenter);
		HP1Text[i]->move(HP1[i]->x(), HP1[i]->y());
		HP1Text[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");
		HP1Text[i]->setFont(HPfont);

		HP2[i] = new QProgressBar();
		HP2[i]->setFixedSize(70, 15);
		HP2[i]->setTextVisible(false);
		HP2[i]->setValue(100);
		HP2[i]->move(player2Pieces[i]->x(), player2Pieces[i]->y()-10);
		HP2Text[i] = new QLabel();
		HP2Text[i]->setFixedSize(HP2[i]->width(), HP2[i]->height());
		HP2Text[i]->setText(QString::number(100) + "/" + QString::number(100));
		HP2Text[i]->setAlignment(Qt::AlignHCenter);
		HP2Text[i]->setAlignment(Qt::AlignCenter);
		HP2Text[i]->move(HP2[i]->x(), HP2[i]->y());
		HP2Text[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");
		HP2Text[i]->setFont(HPfont);
	}

	//���� ���� �� ������ QPushButton�� �����.
	QPixmap pix("./draw/throw.png");
	throwButton = new QPushButton();
	throwButton->setCursor(Qt::PointingHandCursor);
	throwButton->setIcon(QIcon(pix));
	throwButton->setIconSize(pix.rect().size());
    throwButton->setFixedSize(pix.rect().size());
	throwButton->setFlat(true);
    throwButton->setAutoFillBackground(true);
    throwButton->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	throwButton->move(H_LIMIT - 260, -V_LIMIT + 135);

	//���ο� ������ ������ �� ������ ��ư�� �����.
	QPixmap ne("./draw/new.png");
	resetButton = new QPushButton();
	resetButton->setCursor(Qt::PointingHandCursor);
	resetButton->setIcon(QIcon(ne));
	resetButton->setIconSize(ne.rect().size());
    resetButton->setFixedSize(ne.rect().size());
	resetButton->setFlat(true);
    resetButton->setAutoFillBackground(true);
    resetButton->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	resetButton->move(H_LIMIT - 60, V_LIMIT - 90);   //fixedHere

	//���� ���� ������ �����ִ� QGraphicsScene�̴�.
	scene = new QGraphicsScene;

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	StartDisplay* start = new StartDisplay();

	//��� �̹����� �����Ѵ�.
	QImage *background = new QImage();
	background->load("./draw/back.png");	//image�޾ƿ�
	QPixmap ba = QPixmap::fromImage(*background);
	QLabel *back = new QLabel();
	back->setFixedWidth(1200); back->setFixedHeight(730);
	back->move(-H_LIMIT,-V_LIMIT);
	back->setPixmap(ba);
	scene->addWidget(back);

	//�ǹ� ������ ���� QLabel�� �����.
	building = new QLabel();
	QImage *explain = new QImage();
	explain->load("./draw/explain.png");
	QPixmap temp = QPixmap::fromImage(*explain);
	building->setFixedWidth(240); building->setFixedHeight(360);
	building->move(H_LIMIT - 260, -V_LIMIT + 215);
	building->setPixmap(temp);
	building->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	scene->addWidget(building);

	signalMapper3 = new QSignalMapper(this);
	
	//�ǹ� ĭ���� �ʱ�ȭ
	setSpaces();
	turn = true;  //player 1 goes first
	caught = false;

	for(int i = 0; i < PIECE_NUM; i++)
	{
		player1Finished[i] = false;
		player2Finished[i] = false;
	}

	//���� ����ȭ���� startDisplay QGraphicsScene���� �Ѵ�.
	this->setScene(start);

	//Ư�� piece�� �������� �� User�� movePiece �޼��忡 �˸��� ���ڸ� �Ѱ��ֱ� ���ؼ� signalMapper�� ����ߴ�.
	signalMapper1 = new QSignalMapper(player1);
	signalMapper1->setMapping(player1Pieces[0], 0);
	signalMapper1->setMapping(player1Pieces[1], 1);
	signalMapper1->setMapping(player1Pieces[2], 2);
	connect(signalMapper1, SIGNAL(mapped(int)), player1, SLOT(movePiece(int)));
	signalMapper2 = new QSignalMapper(player2);
	signalMapper2->setMapping(player2Pieces[0], 0);
	signalMapper2->setMapping(player2Pieces[1], 1);
	signalMapper2->setMapping(player2Pieces[2], 2);
	connect(signalMapper2, SIGNAL(mapped(int)), player2, SLOT(movePiece(int)));

	//����ȭ�鿡�� ���ӽ����� ������ ������ ���۵ȴ�.
	connect(start->getStartButton(), SIGNAL(clicked()), this, SLOT(StartGame()));
	//���Ӽ����� ������ ���� ������ ���´�.
	connect(start->getExplainButton(), SIGNAL(clicked()), this, SLOT(ExplainGame()));
	//���� ���Ḧ ������ ������ ����ȴ�.
	connect(start->getExitButton(), SIGNAL(clicked()), this, SLOT(ExitGame()));

	connect(throwButton, SIGNAL(clicked()), this, SLOT(selectAndMove()));
	connect(player1, SIGNAL(thrown()), this, SLOT(movePieces()));
	connect(player2, SIGNAL(thrown()), this, SLOT(movePieces()));

	//User�� ����ȭ���� ������Ʈ�϶�� signal�� ������ ȭ���� ������Ʈ�Ѵ�.
	connect(player1, SIGNAL(updateDisplay()), this, SLOT(updateGame()));
	connect(player2, SIGNAL(updateDisplay()), this, SLOT(updateGame()));

	//���� ü���� ������ stealHP�� ����ǵ��� �Ѵ�.
	connect(player1, SIGNAL(lostHP(int)), this, SLOT(stealHP(int)));
	connect(player2, SIGNAL(lostHP(int)), this, SLOT(stealHP(int)));

	//new��ư�� ������ ���ο� ������ ���۵ȴ�.
	connect(resetButton, SIGNAL(clicked()), this, SLOT(newGame()));

	//���� �������� �� unitePieces()�� ����ȴ�.
	connect(player1, SIGNAL(uniteSignal()), this, SLOT(unitePieces()));
	connect(player2, SIGNAL(uniteSignal()), this, SLOT(unitePieces()));

	//���� �����ų� ü���� �� �������� �� resetPieces()�� ����ȴ�.
	connect(player1, SIGNAL(caughtPiece(bool)), this, SLOT(resetPieces(bool)));
	connect(player2, SIGNAL(caughtPiece(bool)), this, SLOT(resetPieces(bool)));
	connect(player1, SIGNAL(die(bool)), this, SLOT(resetPieces(bool)));
	connect(player2, SIGNAL(die(bool)), this, SLOT(resetPieces(bool)));
}

//������ ���� ���۵� �� scene�� QObject���� �߰��ؼ�, ������ �����Ѵ�.
void GameDisplay::StartGame()
{
	sceneAddWidgets();
	bgm->setVolume(15);
}

void GameDisplay::ExplainGame()
{
	explain = new QGraphicsScene();
	back = new QLabel();
	back->setFixedSize(1200, 730);
	back->move(-H_LIMIT, -V_LIMIT);

	for(int i=0;i<19;i++)
	{
		exp[i] = new QImage();
		QString filename = "./draw/ex/"+QString::number(i) + ".png";
		exp[i]->load(filename);
	}

	current = 0;
	back->setPixmap(QPixmap::fromImage(*exp[current]));
	explain->addWidget(back);

	QPushButton *pre = new QPushButton();
	QPushButton *next = new QPushButton();
	pre->setCursor(Qt::PointingHandCursor);
	next->setCursor(Qt::PointingHandCursor);

	QPixmap pix("./draw/ex/pre.png");
	pre->setIcon(QIcon(pix));
	pre->setIconSize(pix.rect().size());
	pre->setFixedSize(50, 50);
	pre->setStyleSheet("background-color: rgba(50, 50, 50, 50%);");
	pre->setFlat(false);
	pre->move(H_LIMIT - 250, -V_LIMIT+ 20);
	explain->addWidget(pre);
	
	QPixmap nex("./draw/ex/next.png");
	next->setIcon(QIcon(nex));
	next->setIconSize(nex.rect().size());
	next->setFixedSize(50, 50);
	next->setStyleSheet("background-color: rgba(50, 50, 50, 50%);");
	next->setFlat(false);
	next->move(H_LIMIT - 200, -V_LIMIT+20);
	explain->addWidget(next);

	resetButton->move(H_LIMIT - 100, -V_LIMIT + 20);
	resetButton->setFixedSize(50, 50);
	explain->addWidget(resetButton);

	connect(pre, SIGNAL(clicked()), this, SLOT(showPre()));
	connect(next, SIGNAL(clicked()), this, SLOT(showNext()));
	
	this->setScene(explain);
}

void GameDisplay::showPre()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/pageTurned.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	current--;
	if(current < 0) current = 0;
	back->setPixmap(QPixmap::fromImage(*exp[current]));
	explain->addWidget(back);
}

void GameDisplay::showNext()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/pageTurned.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();
	current++;
	if(current > 18) current = 18;
	back->setPixmap(QPixmap::fromImage(*exp[current]));
	explain->addWidget(back);
}



//GameDisplay�� �ݾƼ� ������ �����Ѵ�.
void GameDisplay::ExitGame()
{
    this->close();
}

//scene�� QPushButton, QLabel�� QObject���� �߰��Ѵ�.
void GameDisplay::sceneAddWidgets()
{
	scene->addWidget(throwButton);
	scene->addWidget(resetButton);

	//���� �߰��Ѵ�.
	for(int i = 0; i < PIECE_NUM; i++)
	{
		scene->addWidget(player1Pieces[i]);
	}
	for(int i = 0; i < PIECE_NUM; i++)
	{
		scene->addWidget(player2Pieces[i]);
	}

	scene->addWidget(turnLabel);
	scene->addWidget(youtLabel);

	//ü�¹ٸ� �߰��Ѵ�.
	for(int i=0; i<3; i++)
	{
		scene->addWidget(HP1[i]);
		scene->addWidget(HP1Text[i]);
		scene->addWidget(HP2[i]);
		scene->addWidget(HP2Text[i]);
	}

	//GameDisplay�� ���� scene�� scene���� �Ѵ�.
	setScene(scene);
}

//���� ������, ������ �� �ִ� ���� Ŭ�� �����ϰ��Ѵ�.
void GameDisplay::selectAndMove()
{
	//���� ������.
	throwYout();

	//�� �׸��� �׷����ִ� QPushButton�� �����.
	QPushButton *printYout = new QPushButton();
	QPixmap yout("./draw/yout/" + QString::number(randomYout) + ".png");
	printYout->setIconSize(yout.rect().size());
	printYout->setFixedSize(1200, 730);  //ȭ�� �ƹ����̳� ������ ������ ��ư ũ�⸦ �����Ѵ�. 
	printYout->setIcon(QIcon(yout));
	printYout->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
	printYout->move(-H_LIMIT, -V_LIMIT);
	scene->addWidget(printYout);

	//ȭ�� �ƹ����̳� ������ �� �׸��� �������.
	connect(printYout, SIGNAL(clicked()), printYout, SLOT(close()));
	
	if(turn)
	{
		//���� ���� �������� �� �� �ְ� player1Pieces�� Piece1_num �Լ��� �����Ų��.
		connect(player1Pieces[0], SIGNAL(clicked()), this, SLOT(Piece1_num1()));
		connect(player1Pieces[1], SIGNAL(clicked()), this, SLOT(Piece1_num2()));
		connect(player1Pieces[2], SIGNAL(clicked()), this, SLOT(Piece1_num3()));

		for(int i = 0; i < PIECE_NUM; i++)
		{
			//���� ���� �� ���Ƽ� ���� ���¸� ������ ���� �Ұ����ϰ��Ѵ�.
			if(!player1->getPiece(i)->isFinished())
			{
				connect(player1Pieces[i], SIGNAL(clicked()), signalMapper1, SLOT(map()));
			}
		}

		for(int i = 0; i < PIECE_NUM; i++)
		{
			//����(-1)�� ������ �� ������ ���� �ʰų�, ù��° ĭ�� ��ġ�� ���� ������ ���ϰ� �Ѵ�.
			if(randomYout == -1)
			{
				if(player1->getPiece(i)->getPosition() <= 1)
				{
					disconnect(player1Pieces[i], SIGNAL(clicked()), signalMapper1, SLOT(map()));
				}
			}
		}
	}
	else
	{
		connect(player2Pieces[0], SIGNAL(clicked()), this, SLOT(Piece2_num1()));
		connect(player2Pieces[1], SIGNAL(clicked()), this, SLOT(Piece2_num2()));
		connect(player2Pieces[2], SIGNAL(clicked()), this, SLOT(Piece2_num3()));

		for(int i = 0; i < PIECE_NUM; i++)
		{
			if(!player2->getPiece(i)->isFinished())
			{
				connect(player2Pieces[i], SIGNAL(clicked()), signalMapper2, SLOT(map()));
			}
		}

		for(int i = 0; i < PIECE_NUM; i++)
		{
			if(randomYout == -1)
			{
				if(player2->getPiece(i)->getPosition() <= 1)
				{
					disconnect(player2Pieces[i], SIGNAL(clicked()), signalMapper2, SLOT(map()));
				}
			}
		}
	}

	disconnect(throwButton, SIGNAL(clicked()), 0, 0);
}

//���� ���� ������ �������� �� ���� �ش��ϴ� ��ư�� �̹����� �ٲ��ش�.
void GameDisplay::unitePieces()
{
	bool found = false;
	int foundIndex;
	if(turn)
	{
		for(int i = 0; i < PIECE_NUM; i++)
		{
			//�� 2���� ��ģ ���
			if(player1->getPiece(i)->getNum() == 2 && !player1->getPiece(i)->isFinished())
			{
				for(int j = 0; j < PIECE_NUM; j++)
				{
					//���� ���̶� ���� ���̶� ���ƴ��� ã�´�.
					if((i != j) && (player1->getPiece(i) == player1->getPiece(j)))
					{
						//��ģ ������ ã����, �� �� �ϳ��� �� ���̰� �Ѵ�.
						player1Pieces[j]->setVisible(false);
						HP1[j]->setVisible(false);
						HP1Text[j]->setVisible(false);
						foundIndex = j;
						found = true;
					}
				}
				//��, �׸��� ü�¹��� �̹����� �ٲ۴�.
				player1Pieces[i]->setIcon(QIcon("./characters/red" + QString::number(i) + QString::number(foundIndex) + ".png"));
				HP1[i]->setValue(player1->getPiece(i)->getHP() / player1->getPiece(i)->getNum());
				HP1Text[i]->setText(QString::number(player1->getPiece(i)->getHP()) + "/" + QString::number(player1->getPiece(i)->getNum()*100));
			}
			if(found)   //���� ���� ���ƴ� �� ã������, while���� �������´�.
			{
				break;
			}

			//���� 3�� ��ģ ���
			if(player1->getPiece(i)->getNum() == 3 && !player1->getPiece(i)->isFinished())
			{
				//��ư �ϳ� ���� ���� �ش��ϴ� ��ư�� �� �� ���̰� �Ѵ�.
				for(int j = 0; j < PIECE_NUM; j++)
				{
					if(i != j)
					{
						player1Pieces[j]->setVisible(false);
						HP1[j]->setVisible(false);
						HP1Text[j]->setVisible(false);
						found = true;
					}
				}
				//�� �̹���, �׸��� ü�¹ٸ� ������Ʈ�Ѵ�.
				player1Pieces[i]->setIcon(QIcon("./characters/red3Pieces.png"));
				HP1[i]->setValue(player1->getPiece(i)->getHP() / player1->getPiece(i)->getNum());
				HP1Text[i]->setText(QString::number(player1->getPiece(i)->getHP()) + "/" + QString::number(player1->getPiece(i)->getNum()*100));
			}
			if(found)
			{
				break;
			}
		}
	}
	else
	{
		for(int i = 0; i < PIECE_NUM; i++)
		{
			if(player2->getPiece(i)->getNum() == 2 && !player2->getPiece(i)->isFinished())
			{
				for(int j = 0; j < PIECE_NUM; j++)
				{
					if((i != j) && (player2->getPiece(i) == player2->getPiece(j)))
					{
						player2Pieces[j]->setVisible(false);
						HP2[j]->setVisible(false);
						HP2Text[j]->setVisible(false);
						foundIndex = j;
						found = true;
					}
				}
				player2Pieces[i]->setIcon(QIcon("./characters/blue" + QString::number(i) + QString::number(foundIndex) + ".png"));
				HP2[i]->setValue(player2->getPiece(i)->getHP() / player2->getPiece(i)->getNum());
				HP2Text[i]->setText(QString::number(player2->getPiece(i)->getHP()) + "/" + QString::number(player2->getPiece(i)->getNum()*100));
			}
			if(found)
			{
				break;
			}


			if(player2->getPiece(i)->getNum() == 3 && !player2->getPiece(i)->isFinished())
			{
				for(int j = 0; j < PIECE_NUM; j++)
				{
					if(i != j)
					{
						player2Pieces[j]->setVisible(false);
						HP2[j]->setVisible(false);
						HP2Text[j]->setVisible(false);
						found = true;
					}
				}
				player2Pieces[i]->setIcon(QIcon("./characters/blue3Pieces.png"));
				HP2[i]->setValue(player2->getPiece(i)->getHP() / player2->getPiece(i)->getNum());
				HP2Text[i]->setText(QString::number(player2->getPiece(i)->getHP()) + "/" + QString::number(player2->getPiece(i)->getNum()*100));
			}
			if(found)
			{
				break;
			}
		}
	}
}

//���� �ٸ� ���� ������ ������, ó������ �ٽ� ������.
void GameDisplay::resetPieces(bool isCaught)
{
	for(int i = 0; i < PIECE_NUM; i++)
	{
		//�����ų�, ���� �������� �ִ� ������ ������ ���д�.
		if(!player2->getPiece(i)->isFinished() && player2->getPiece(i)->getPosition() == 0)
		{
			//���� ó������ �ʱ�ȭ�Ѵ�.
			player2Pieces[i]->setVisible(true);
			HP2[i]->setVisible(true);
			HP2Text[i]->setVisible(true);
			player2Pieces[i]->setIcon(QIcon("./characters/char2" + QString::number(i+1) + ".png"));
			HP2[i]->setValue(100);
			HP2Text[i]->setText("100/100");
			player2Pieces[i]->move(H_LIMIT - 270 + 70*i, V_LIMIT - 100);
			HP2[i]->move(player2Pieces[i]->x(), player2Pieces[i]->y());
			HP2Text[i]->move(HP2[i]->x(), HP2[i]->y());
		}

		if(!player1->getPiece(i)->isFinished() && player1->getPiece(i)->getPosition() == 0)
		{
			player1Pieces[i]->setVisible(true);
			HP1[i]->setVisible(true);
			HP1Text[i]->setVisible(true);
			player1Pieces[i]->setIcon(QIcon("./characters/char1" + QString::number(i+1) + ".png"));
			HP1[i]->setValue(100);
			HP1Text[i]->setText("100/100");
			player1Pieces[i]->move(H_LIMIT - 270 + 70*i, V_LIMIT - 150);
			HP1[i]->move(player1Pieces[i]->x(), player1Pieces[i]->y());
			HP1Text[i]->move(HP1[i]->x(), HP1[i]->y());
		}
	}

	caught = isCaught;    //���� ������ ���� �ϳ� �� �����Ƿ�, �̸� �Ǻ��ϱ� ���ؼ� ���� ����� �� caught ������ true�� �����ǰ� �ߴ�.
}

//���� ���� ������ �����ش�.
void GameDisplay::showTurn()
{
	if(!turn)
	{
		turnLabel->setText("Player1's turn!!");
	}
	else
	{
		turnLabel->setText("Player2's turn!!");
	}
}

//���� ������.
void GameDisplay::throwYout()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/youtsThrown.mp3"));
	sound->setVolume(FX_VOLUME);
	sound->play();

	srand(time(NULL));

    int yout = rand()%16;

	//���� ���� Ȯ���� �����.
    if(yout < 1)
        yout = -1;
    else if(yout < 4)
        yout = 1;//��
    else if(yout < 10)
        yout = 2;//��
    else if(yout < 14)
        yout = 3;//��
    else if(yout < 15)
        yout = 4;//��
    else
        yout = 5;//��

	bool backPossible = false;

	//������ �������� Ȯ���Ѵ�.
	if(yout == -1)
	{
		if(turn)
		{
			for(int i = 0; i < PIECE_NUM; i++)
			{
				if(player1->getPiece(i)->getPosition() > 1 && !player1->getPiece(i)->isFinished())
				{
					backPossible = true;
				}
			}
		}
		else
		{
			for(int i = 0; i < PIECE_NUM; i++)
			{
				if(player2->getPiece(i)->getPosition() > 1 && !player2->getPiece(i)->isFinished())
				{
					backPossible = true;
				}
			}
		}
	}

	//������ �������� �ʴٸ�, �׳� ��(1)�� �ٲ۴�.
	if(!backPossible && yout == -1)
	{
		yout = 1;
	}

	//���� ���� randomYout�� yout���� �����Ѵ�.
	randomYout = yout;

	youtLabel->setText(QString::number(randomYout));
}

//���� ��Ȳ�� �°� ���� ȭ���� ������Ʈ�Ѵ�.
void GameDisplay::updateGame()
{
	//player1�̳� player2�� �̱�� ����� ����.
	if(player1->win())
	{
		sound->setMedia(QUrl::fromLocalFile("./sounds/win.wav"));
		sound->setVolume(FX_VOLUME);
		sound->play();
		QLabel* label1 = new QLabel();
		QPixmap pix1(":/images/player1_victory.png");
		label1->setPixmap(pix1);
		label1->setFixedSize(pix1.rect().size());
		label1->move(-label1->width()/2, -label1->height()/2);
		label1->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		scene->addWidget(label1);

		QImage *explain = new QImage();	
		explain->load("./draw/explain.png");
		QPixmap temp = QPixmap::fromImage(*explain);
		building->setPixmap(temp);
		scene->addWidget(building);
	}
	else if(player2->win())
	{
		sound->setMedia(QUrl::fromLocalFile("./sounds/win.wav"));
		sound->setVolume(FX_VOLUME);
		sound->play();
		QLabel* label2 = new QLabel();
		QPixmap pix2(":/images/player2_victory.png");
		label2->setPixmap(pix2);
		label2->setFixedSize(pix2.rect().size());
		label2->move(-label2->width()/2, -label2->height()/2);
		label2->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		scene->addWidget(label2);

		QImage *explain = new QImage();
		explain->load("./draw/explain.png");
		QPixmap temp = QPixmap::fromImage(*explain);
		building->setPixmap(temp);
		scene->addWidget(building);
	}

	youtLabel->clear();

	//��(4)�̳� ��(5)�� ������, �ٸ� ������ turn�� �ٲ��� �ʴ´�.
	if(randomYout == 4 || randomYout ==5)
	{
		turn = turn;
	}
	else if(caught)  //������ ���� ��Ƶ� ���� �ѱ��� �ʴ´�.
	{
		turn = turn;
	}
	else
	{
		showTurn();
		turn = !turn;   //�������� ���� �ѱ��.
	}

	//���ο� ���� �����ϱ� ���� �غ� �Ѵ�.
	caught = false;
	connect(throwButton, SIGNAL(clicked()), this, SLOT(selectAndMove()));
}

//�� ���� ��ġ�� �°� ���� �����δ�.
void GameDisplay::movePieces()
{
	sound->setMedia(QUrl::fromLocalFile("./sounds/pieceMoved.wav"));
	sound->setVolume(FX_VOLUME);
	sound->play();

	int xPos;
	int yPos;
	int position1, position2;

	for(int i = 0; i < PIECE_NUM; i++)
	{
		//���� ������ �ʰ�, ��ġ�� �������� �ƴ� ��, �˸´� ��ġ�� ���� �ű��.
		if(!player1->getPiece(i)->isFinished() && player1->getPiece(i)->getPosition() != 0)
		{
			xPos = gameBoard->getSpace(player1->getPiece(i)->getPosition())->getXPosition();
			yPos = gameBoard->getSpace(player1->getPiece(i)->getPosition())->getYPosition();
			
			position1 = player1->getPiece(i)->getPosition();
			if(position1 == 5 || position1 == 10 || position1 == 15 || position1 == 22)
				player1Pieces[i]->move(xPos + 25, yPos + 5);
			else player1Pieces[i]->move(xPos + 25, yPos - 10);
		}
		else if(player1->getPiece(i)->isFinished())
		{
			if(!player1Finished[i])
			{
				sound->setMedia(QUrl::fromLocalFile("./sounds/finished.wav"));
				sound->setVolume(FX_VOLUME);
				sound->play();
				player1Finished[i] = true;
			}
			//���� ���� �� ���Ƽ� ������, �̹����� �ٲ۴�. ü�¹ٵ� ���ش�.
			player1Pieces[i]->setVisible(true);
			player1Pieces[i]->setIcon(QIcon("./characters/finished1" + QString::number(i+1) + ".png"));
			player1Pieces[i]->resize(BUTTON_WIDTH, BUTTON_HEIGHT);
			player1Pieces[i]->setIconSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			player1Pieces[i]->move(H_LIMIT - 270 + 70*i, V_LIMIT - 150);
			player1Pieces[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");
			HP1[i]->setVisible(false);
			HP1Text[i]->setVisible(false);
		}
		HP1[i]->move(player1Pieces[i]->x(), player1Pieces[i]->y()-10);
		HP1Text[i]->move(HP1[i]->x(), HP1[i]->y());
	}

	for(int i = 0; i < PIECE_NUM; i++)
	{
		if(!player2->getPiece(i)->isFinished() && player2->getPiece(i)->getPosition() != 0)
		{
			xPos = gameBoard->getSpace(player2->getPiece(i)->getPosition())->getXPosition();
			yPos = gameBoard->getSpace(player2->getPiece(i)->getPosition())->getYPosition();
			
			position2 = player2->getPiece(i)->getPosition();
			if(position2 == 5 || position2 == 10 || position2 == 15 || position2 == 22)
				player2Pieces[i]->move(xPos + 25, yPos + 5);
			else player2Pieces[i]->move(xPos + 25, yPos - 10);
		}
		else if(player2->getPiece(i)->isFinished())
		{
			if(!player2Finished[i])
			{
				sound->setMedia(QUrl::fromLocalFile("./sounds/finished.wav"));
				sound->setVolume(FX_VOLUME);
				sound->play();
				player2Finished[i] = true;
			}
			player2Pieces[i]->setVisible(true);
			player2Pieces[i]->setIcon(QIcon("./characters/finished2" + QString::number(i+1) + ".png"));
			player2Pieces[i]->resize(BUTTON_WIDTH, BUTTON_HEIGHT);
			player2Pieces[i]->setIconSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			player2Pieces[i]->move(H_LIMIT - 270 + 70*i, V_LIMIT - 100);
			player2Pieces[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");
			HP2[i]->setVisible(false);
			HP2Text[i]->setVisible(false);
		}
		HP2[i]->move(player2Pieces[i]->x(), player2Pieces[i]->y()-10);
		HP2Text[i]->move(HP2[i]->x(), HP2[i]->y());
	}

	if(turn)
	{
		QImage *build = new QImage();
		QString filename;
		if(player1->getPiece(piece1_num)->isFinished())
			filename = "./draw/explain.png";
		else
		{
			//������ ���� ������ ���� �ǹ� ������ �Ѵ�.
			position1 = player1->getPiece(piece1_num)->getPosition();
			filename = "./draw/building/" + QString::number(position1) + ".png";
		}
		build->load(filename);
		building->setPixmap(QPixmap::fromImage(*build));
		scene->addWidget(building);
	}
	else
	{
		QImage *build = new QImage();
		QString filename;
		if(player2->getPiece(piece2_num)->isFinished())
			filename = "./draw/explain.png";
		else
		{
			position2 = player2->getPiece(piece2_num)->getPosition();
			filename = "./draw/building/" + QString::number(position2) + ".png";
		}
		build->load(filename);
		building->setPixmap(QPixmap::fromImage(*build));
		scene->addWidget(building);
	}

	//���� ������ ���� �ش��ϴ� ��ư�� ����� ���´�.
	if(turn)
	{
		disconnect(player1Pieces[0], SIGNAL(clicked()), 0, 0);
		disconnect(player1Pieces[1], SIGNAL(clicked()), 0, 0);
		disconnect(player1Pieces[2], SIGNAL(clicked()), 0, 0);
	}
	else
	{
		disconnect(player2Pieces[0], SIGNAL(clicked()), 0, 0);
		disconnect(player2Pieces[1], SIGNAL(clicked()), 0, 0);
		disconnect(player2Pieces[2], SIGNAL(clicked()), 0, 0);
	}
}

//���ο� ������ �����Ѵ�.
void GameDisplay::newGame()
{
	sound->stop();
	player1->getSound()->stop();
	player2->getSound()->stop();
	initializeGame();
}

//ĭ�� �ش��ϴ� �׸��� �׸���.
void GameDisplay::setSpaces()
{
	for (int i = 0; i < 29; i++)
	{
		image[i] = new QPushButton();
		image[i]->setFlat(true);
		image[i]->setAutoFillBackground(true);
		image[i]->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
		
		if (i < 5)
		{
			if (i == 0) image[i]->setFixedHeight(120);
			else image[i]->setFixedHeight(80);
			image[i]->setGeometry(QRect(180, V_LIMIT - 145 - (image[i]->height() + 24) * i, image[i]->width(), image[i]->height()));
			gameBoard->getSpace(i)->setPosition(180, V_LIMIT - 145 - (image[i]->height() + 24) * i);
		}
		else if (i < 10)
		{
			if (i == 5)
			{
				image[i]->setFixedHeight(120);
				image[i]->setGeometry(QRect(180 - 150 * (i - 5), - V_LIMIT + 25, image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(180 - 150 * (i - 5), - V_LIMIT + 25);
			}
			else
			{
				image[i]->setFixedHeight(80);
				image[i]->setGeometry(QRect(180 - 150 * (i - 5), -V_LIMIT + 45, image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(180 - 150 * (i - 5), -V_LIMIT + 45);
			}
		}
		else if (i < 15)
		{
			if (i == 10)
			{
				image[i]->setFixedHeight(120);
				image[i]->setGeometry(QRect(-H_LIMIT + 30, -V_LIMIT + 25, image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(-H_LIMIT + 30, -V_LIMIT + 25);
			}
			else
			{
				image[i]->setFixedHeight(80);
				image[i]->setGeometry(QRect(-H_LIMIT + 30, -V_LIMIT + 65 + (image[i]->height() + 24) * (i - 10), image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(-H_LIMIT + 30, -V_LIMIT + 65 + (image[i]->height() + 24) * (i - 10));
			}
		}
		else if (i < 20)
		{
			if (i == 15)
			{
				image[i]->setFixedHeight(120);
				image[i]->setGeometry(QRect(-H_LIMIT + 30 + 150 * (i - 15), -V_LIMIT + 585, image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(-H_LIMIT + 30 + 150 * (i - 15), -V_LIMIT + 585);
			}
			else
			{
				image[i]->setFixedHeight(80);
				image[i]->setGeometry(QRect(-H_LIMIT + 30 + 150 * (i - 15), -V_LIMIT + 605, image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(-H_LIMIT + 30 + 150 * (i - 15), -V_LIMIT + 605);
			}
		}
		else if(i < 29)
		{
			if (i == 22)
			{
				image[i]->setFixedHeight(120);
				image[i]->setGeometry(QRect(-H_LIMIT + 405, -V_LIMIT + 305, image[i]->width(), image[i]->height()));
				gameBoard->getSpace(i)->setPosition(-H_LIMIT + 405, -V_LIMIT + 305);
			}
			else
			{
				image[i]->setFixedWidth(125);
				image[i]->setFixedHeight(132);
			}
		}
	}
	image[20]->setGeometry(QRect(-H_LIMIT + 635, -V_LIMIT + 130, image[20]->width(), image[20]->height()));
	image[21]->setGeometry(QRect(-H_LIMIT + 530, -V_LIMIT + 210, image[21]->width(), image[21]->height()));
	image[23]->setGeometry(QRect(-H_LIMIT + 275, -V_LIMIT + 388, image[23]->width(), image[23]->height()));
	image[24]->setGeometry(QRect(-H_LIMIT + 170, -V_LIMIT + 468, image[24]->width(), image[24]->height()));
	image[25]->setGeometry(QRect(-H_LIMIT + 170, -V_LIMIT + 130, image[25]->width(), image[25]->height()));
	image[26]->setGeometry(QRect(-H_LIMIT + 275, -V_LIMIT + 210, image[26]->width(), image[26]->height()));
	image[27]->setGeometry(QRect(-H_LIMIT + 530, -V_LIMIT + 388, image[27]->width(), image[27]->height()));
	image[28]->setGeometry(QRect(-H_LIMIT + 635, -V_LIMIT + 468, image[28]->width(), image[28]->height()));
	gameBoard->getSpace(20)->setPosition(-H_LIMIT + 635, -V_LIMIT + 130);
	gameBoard->getSpace(21)->setPosition(-H_LIMIT + 530, -V_LIMIT + 210);
	gameBoard->getSpace(23)->setPosition(-H_LIMIT + 275, -V_LIMIT + 388);
	gameBoard->getSpace(24)->setPosition(-H_LIMIT + 170, -V_LIMIT + 468);
	gameBoard->getSpace(25)->setPosition(-H_LIMIT + 170, -V_LIMIT + 130);
	gameBoard->getSpace(26)->setPosition(-H_LIMIT + 275, -V_LIMIT + 210);
	gameBoard->getSpace(27)->setPosition(-H_LIMIT + 530, -V_LIMIT + 388);
	gameBoard->getSpace(28)->setPosition(-H_LIMIT + 635, -V_LIMIT + 468);

	for(int i=0; i < 29; i++)
		signalMapper3->setMapping(image[i], i);
	connect(signalMapper3, SIGNAL(mapped(int)), this, SLOT(explainSpace(int)));

	for (int i = 0; i < 29; i++)
	{
		QPixmap spaceImage("./draw/space/" + QString::number(i) + ".png");
		image[i]->setIconSize(spaceImage.rect().size());
		image[i]->setFixedSize(spaceImage.rect().size());
		image[i]->setIcon(QIcon(spaceImage));
		connect(image[i], SIGNAL(clicked()), signalMapper3, SLOT(map()));
		scene->addWidget(image[i]);
	}
}

//���� ���� �ڱ� �ǹ��� �ɷ��� �� ü���� ���´�.
void GameDisplay::stealHP(int damage)
{
	if(!turn)
	{
		for(int i=0; i<3; i++)
		{
			player1->getPiece(i)->get_heal(damage/3);
			HP1[i]->setValue(player1->getPiece(i)->getHP() / player1->getPiece(i)->getNum());
			HP1Text[i]->setText(QString::number(player1->getPiece(i)->getHP()) + "/" + QString::number(player1->getPiece(i)->getNum()*100));
		}
	}
	else
	{
		for(int i=0; i<3; i++)
		{
			player2->getPiece(i)->get_heal(damage/3);
			HP2[i]->setValue(player2->getPiece(i)->getHP() / (player2->getPiece(i)->getNum()));
			HP2Text[i]->setText(QString::number(player2->getPiece(i)->getHP()) + "/" + QString::number(player2->getPiece(i)->getNum()*100));
		}
	}
}

//ü�¹ٸ� ������Ʈ�Ѵ�.
void GameDisplay::setHPText(int i, int team, int hp, int maxhp)
{
	if(!team)
	{
		HP1[i]->setValue(hp * 100 / maxhp);
		HP1Text[i]->setText(QString::number(hp) + "/" + QString::number(maxhp));
	}
	else
	{
		HP2[i]->setValue(hp * 100 / maxhp);
		HP2Text[i]->setText(QString::number(hp) + "/" + QString::number(maxhp));
	}
}

//�ǹ� ������ ����.
void GameDisplay::explainSpace(int position)
{
	QImage *build = new QImage();
	QString filename = "./draw/building/" + QString::number(position) + ".png";
	build->load(filename);
	building->setPixmap(QPixmap::fromImage(*build));
	scene->addWidget(building);
}

GameDisplay::~GameDisplay()
{
}