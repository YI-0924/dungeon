//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#include"Hero.h"
#include"Creature.h"
#include"Trigger.h"


//Set position
void Hero::setPosH(PositionH pos)
{
	this->HeroPos = pos;
}

//Set position
void Hero::setPosH(int x, int y)
{
	this->HeroPos.x = x;
	this->HeroPos.y = y;
}

// Set icon
void Hero::setIconH(char icon)
{
	this->HeroIcon = icon;
}

//Set blood
void Hero::setBloodH(int b)
{
	this->HeroBlood = b;
}

//Set attack
void Hero::setAttackH(int a)
{
	this->HeroAttack = a;
}

//Set exp
void Hero::setExpH(int c)
{
	this->HeroExp = c;
}

// Get position
PositionH Hero::getPosH(void)
{
	return this->HeroPos;
}

// Get Icon
char Hero::getIconH(void)
{
	return this->HeroIcon;
}

//Get blood
int Hero::getBloodH(void)
{
	return this->HeroBlood;
}

//Get attack
int Hero::getAttackH(void)
{
	return this->HeroAttack;
}

//Get exp
int Hero::getExpH(void)
{
	return this->HeroExp;
}

void Hero::drawBoard(vector< vector<char> >& maze, int x, int y, int xCreature, int yCreature)
{

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (x == j && y == i && i != 0 && j != 0) {
				cout << this->HeroIcon;
			}
			else if (j == 7 && i == 7) {
				cout << 't';
			}
			else if (xCreature == j && yCreature == i && xCreature != 0 && yCreature != 0) {
				if (xCreature == x && yCreature == y)
				{
					//cout << "Dead!\n";
					//system("pause");
					break;
				}
				else
				{
					cout << 'c';
				}
			}
			else {
				cout << maze[i][j];
			}
		}
		cout << "\n\n";
	}

}

void Hero::makeBoard(vector< vector<char> >& maze, int* x, int* y)
{

	maze =
	{
		{'#','#','#','#','#','#','#','#','#','#','#','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#','#','#','#','#','#','#','#','#','#','#','#'}
	};

	//*x = 1;
	//*y = 1;

}

void Hero::modifyBoard(vector< vector<char> >& maze, int* x, int* y, int* xCreature, int* yCreature, char dir, string act, int a, int b)
{

	system("cls");
	//cout << "移動方向鍵: w:上  s:下  a:左  d:右  q:離開" << "\n";


	switch (dir) {
	case 'a':
		if (*x != 1 && maze[*y][*x - 1] != '#')
		{
			maze[*y][*x] = ' ';
			*x = *x - 1;
		}
		drawBoard(maze, *x, *y, *xCreature, *yCreature);
		break;
	case 's':
		if (*y != (SIZE - 1) && maze[*y + 1][*x] != '#')
		{
			maze[*y][*x] = ' ';
			*y = *y + 1;
		}
		drawBoard(maze, *x, *y, *xCreature, *yCreature);
		break;
	case 'd':
		if (*x != (SIZE - 1) && maze[*y][*x + 1] != '#')
		{
			maze[*y][*x] = ' ';
			*x = *x + 1;
		}
		drawBoard(maze, *x, *y, *xCreature, *yCreature);
		break;
	case 'w':
		if (*y != 1 && maze[*y - 1][*x] != '#')
		{
			maze[*y][*x] = ' ';
			*y = *y - 1;
		}
		drawBoard(maze, *x, *y, *xCreature, *yCreature);
		break;
	case 'q':
		system("pause");
	default:
		drawBoard(maze, 1, 1, 6, 6);
	}
}

Hero::~Hero()
{

}
