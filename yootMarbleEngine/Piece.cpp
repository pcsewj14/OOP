#include "Piece.h"

Piece::Piece()
{
	maxHP = 100;
	HP = 100;
	position = 0;
	finished = false;
	num = 1;
}

//말을 움직인다.
void Piece::move(int move_num)
{
	bool canFinish = false;

	//말이 이 위치에 있으면 판을 다 돌 수 있어서, canFinish를 true로 했다.
	if(position >= 15 && position <= 19)
	{
		canFinish = true;
	}

	if(position < 2 && move_num == -1)
	{
		return;
	}

	if(position == 5)
	{
		if(move_num == -1)
		{
			position = 4;
		}
		else
		{
			position = 19 + move_num;
		}
	}
	else if(position == 10)
	{
		if(move_num == -1)
		{
			position = 9;
		}
		else if(move_num < 3)
		{
			position = 24 + move_num;
		}
		else if(move_num == 3)
		{
			position = 22;
		}
		else if(move_num > 3)
		{
			position = 23 + move_num;
		}
	}
	else if(position == 22)  //말이 가운데 칸에 있는 경우
	{
		if(move_num == -1)
		{
			position = 21;
		}
		else
		{
			position = 26 + move_num;
		}
	}
	else if(position >= 20 && position <= 24)
	{
		if(position == 20 && move_num == -1)
		{
			position = 6;
		}
		position += move_num;
		if(position > 24)
		{
			position -= 10;
		}
	}
	else if(position == 25)
	{
		if(move_num == 1)
		{
			position = 26;
		}
		else if(move_num == -1)
		{
			position = 10;
		}
		else if(move_num == 2)
		{
			position = 22;
		}
		else
		{
			position += move_num;
			position -= 1;
		}
	}
	else if(position == 26)
	{
		if(move_num == -1)
		{
			position = 25;
		}
		else if(move_num == 1)
		{
			position = 22;
		}
		else
		{
			position += move_num;
			position -= 1;
		}
	}
	else if(position == 27 && move_num == -1)
		position = 22;
	else
	{
		position += move_num;
	}

	//말을 끝낸다.
	if(position > 28)
	{
		finish();
	}

	if(canFinish && (position > 19))
	{
		finish();
	}
}

//말이 데미지를 입는다.
bool Piece::get_damage(int damage)
{
    HP -= damage;
    if(HP <= 0)
	{
		HP = 0;
        return true;   //말이 죽으면 true를 반환
	}
    else
        return false;
}

//말이 체력을 회복한다.
void Piece::get_heal(int heal)
{
    HP += heal;
    if(HP > maxHP)
        HP = maxHP;
}

//말을 끝낸다.
void Piece::finish()
{
	finished = true;
}

//말의 최대 체력을 설정한다.
void Piece::setMaxHP(int maxHP)
{
    this->maxHP = maxHP;
}

//말을 원하는 곳으로 보낸다.
void Piece::setPosition(int position)
{
    this->position = position;
}

int Piece::getHP()
{
    return HP;
}

int Piece::getPosition()
{
    return position;
}