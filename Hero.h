//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#ifndef Hero_H
#define Hero_H
#include <iostream>
#include<vector>
#define SIZE 12

using namespace std;

struct PositionH
{
	int x;		// x, y Coordinate
	int y;
};

class Hero
{
private:

	PositionH	HeroPos;			// Hero location
	char HeroIcon = 'H';			// Hero icon
	int HeroBlood = 100;			// Hero blood
	int HeroAttack = 1;				// Hero level
	int HeroExp = 0;				// Hero exp

public:
	// Default constructor
	Hero()
	{

		this->HeroPos.x = 0;
		this->HeroPos.y = 0;
		this->HeroIcon = 'H';
		this->HeroBlood = 100;
		this->HeroAttack = 1;
		this->HeroExp = 0;

	};


	// Set position
	void setPosH(PositionH pos);
	void setPosH(int x, int y);

	// Set icon
	void setIconH(char icon);

	//Set blood
	void setBloodH(int b);

	//Set attack
	void setAttackH(int a);

	//Set exp
	void setExpH(int c);

	// Get position
	PositionH getPosH(void);

	// Get Icon
	char getIconH(void);

	//Get blood
	int getBloodH(void);

	//Get attack
	int getAttackH(void);

	//Get exp
	int getExpH(void);

	//Draw the maze and check if the hero is dead
	void drawBoard(vector< vector<char> >& maze, int x, int y, int xCreature, int yCreature);

	//Initialization the maze
	void makeBoard(vector< vector<char> >& maze, int* x, int* y);

	//How hero move in the maze (direction)
	void modifyBoard(vector< vector<char> >& maze, int* x, int* y, int* xCreature, int* yCreature, char dir, string act, int a,int b);

	~Hero();

};

#endif			//Hero_H
