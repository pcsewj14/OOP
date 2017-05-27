#include "Piece.h"

Piece::Piece()
{
	maxHP = 100;
	HP = 100;
	position = 0;
	finished = false;
	num = 1;
}

//���� �����δ�.
void Piece::move(int move_num)
{
	bool canFinish = false;

	//���� �� ��ġ�� ������ ���� �� �� �� �־, canFinish�� true�� �ߴ�.
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
	else if(position == 22)  //���� ��� ĭ�� �ִ� ���
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

	//���� ������.
	if(position > 28)
	{
		finish();
	}

	if(canFinish && (position > 19))
	{
		finish();
	}
}

//���� �������� �Դ´�.
bool Piece::get_damage(int damage)
{
    HP -= damage;
    if(HP <= 0)
	{
		HP = 0;
        return true;   //���� ������ true�� ��ȯ
	}
    else
        return false;
}

//���� ü���� ȸ���Ѵ�.
void Piece::get_heal(int heal)
{
    HP += heal;
    if(HP > maxHP)
        HP = maxHP;
}

//���� ������.
void Piece::finish()
{
	finished = true;
}

//���� �ִ� ü���� �����Ѵ�.
void Piece::setMaxHP(int maxHP)
{
    this->maxHP = maxHP;
}

//���� ���ϴ� ������ ������.
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