//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#include"Creature.h"
#include"Hero.h"
#include"Trigger.h"



//Set position
void Creature::setPosC(PositionC pos)
{
	this->CreaturePos = pos;
}

//Set position
void Creature::setPosC(int x, int y)
{
	this->CreaturePos.x = x;
	this->CreaturePos.y = y;
}

//Set icon
void Creature::setIconC(char icon)
{
	this->CreatureIcon = icon;
}

//Set blood
void Creature::setBloodC(int b)
{
	this->CreatureBlood = b;
}

//Set attack
void Creature::setAttackC(int a)
{
	this->CreatureAttack = a;
}

//Get position
PositionC Creature::getPosC(void)
{
	return this->CreaturePos;
}

//Get icon
char Creature::getIconC(void)
{
	return this->CreatureIcon;
}

//Get blood
int Creature::getBloodC(void)
{
	return this->CreatureBlood;
}

//Get attack
int Creature::getAttackC(void)
{
	return this->CreatureAttack;
}

//Whether the creature see the hero, cout the message, calculate the direction, and move relatively
PositionC Creature::canSee(int x, int y, int xCreature, int yCreature)
{
	PositionC cPos;
	cPos.x = xCreature;
	cPos.y = yCreature;

	if (x == xCreature && y == yCreature)
	{
		return cPos;
	}

	//上下兩格內 and move near the hero
	if (x == xCreature && (y + 2 == yCreature || y + 1 == yCreature))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Hero 在 Creature 的 上方\n";
		if (yCreature != 0 && yCreature != 1) {
			cPos.x = xCreature;
			cPos.y = yCreature - 1;
		}
	}
	else if (x == xCreature && (y - 2 == yCreature || y - 1 == yCreature))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Hero 在 Creature 的 下方\n";
		if (yCreature != 10 && yCreature != 11)
		{
			cPos.x = xCreature;
			cPos.y = yCreature + 1;
		}
	}

	//左右兩格內 and move near the hero
	else if (y == yCreature && (x + 2 == xCreature || x + 1 == xCreature))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Hero 在 Creature 的 左方\n";
		if (xCreature != 0 && xCreature != 1)
		{
			cPos.x = xCreature - 1;
			cPos.y = yCreature;
		}
	}
	else if (y == yCreature && (x - 2 == xCreature || x - 1 == xCreature))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Hero 在 Creature 的 右方\n";
		if (xCreature != 10 && xCreature != 11)
		{
			cPos.x = xCreature + 1;
			cPos.y = yCreature;
		}
	}

	//右上右下兩格內 and move near the hero
	else if ((xCreature == x + 1 && yCreature == y - 1) || (xCreature == x + 2 && yCreature == y - 2))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Creature 在 Hero 的 右上方\n";
		srand(time(NULL));
		int randomWalk;
		randomWalk = rand() % 2 + 1;
		if (randomWalk == 1 && xCreature != 0 && xCreature != 1)
		{
			cPos.x = xCreature - 1;
			cPos.y = yCreature;
		}
		else if (yCreature != 10 && yCreature != 11) {
			cPos.x = xCreature;
			cPos.y = yCreature + 1;
		}
	}
	else if ((xCreature == x + 1 && yCreature == y + 1) || (xCreature == x + 2 && yCreature == y + 2))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Creature 在 Hero 的 右下方\n";
		srand(time(NULL));
		int randomWalk;
		randomWalk = rand() % 2 + 1;
		if (randomWalk == 1 && xCreature != 0 && xCreature != 1)
		{
			cPos.x = xCreature - 1;
			cPos.y = yCreature;
		}
		else if (yCreature != 0 && yCreature != 1) {
			cPos.x = xCreature;
			cPos.y = yCreature - 1;
		}
	}

	//左上左下兩格內 and move near the hero
	else if ((xCreature == x - 1 && yCreature == y - 1) || (xCreature == x - 2 && yCreature == y - 2))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Creature 在 Hero 的 左上方\n";
		srand(time(NULL));
		int randomWalk;
		randomWalk = rand() % 2 + 1;
		if (randomWalk == 1 && xCreature != 10 && xCreature != 11)
		{
			cPos.x = xCreature + 1;
			cPos.y = yCreature;
		}
		else if (yCreature != 10 && yCreature != 11) {
			cPos.x = xCreature;
			cPos.y = yCreature + 1;
		}
	}
	else if ((xCreature == x - 1 && yCreature == y + 1) || (xCreature == x - 2 && yCreature == y + 2))
	{
		cout << "Creature 看到 Hero 了!\n";
		cout << "Creature 在 Hero 的 左下方\n";
		srand(time(NULL));
		int randomWalk;
		randomWalk = rand() % 2 + 1;
		if (randomWalk == 1 && xCreature != 10 && xCreature != 11)
		{
			cPos.x = xCreature + 1;
			cPos.y = yCreature;
		}
		else if (yCreature != 0 && yCreature != 1) {
			cPos.x = xCreature;
			cPos.y = yCreature - 1;
		}
	}

	//creature cannot see the hero
	else {
		srand(time(NULL));
		int randomWalk;
		randomWalk = rand() % 4 + 1;
		switch (randomWalk)
		{
		case 1:
			if (xCreature != 1 && xCreature != 0)
			{
				cPos.x = xCreature - 1;
				cPos.y = yCreature;
			}
			break;
		case 2:
			if (xCreature != 11 && xCreature != 10)
			{
				cPos.x = xCreature + 1;
				cPos.y = yCreature;
			}
			break;
		case 3:
			if (yCreature != 1 && yCreature != 0)
			{
				cPos.x = xCreature;
				cPos.y = yCreature - 1;
			}
			break;
		case 4:
			if (yCreature != 11 && yCreature != 10)
			{
				cPos.x = xCreature;
				cPos.y = yCreature + 1;
			}
			break;
		}
	}

	return cPos;
}

Creature::~Creature()
{

}
