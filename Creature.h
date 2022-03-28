//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#ifndef Creature_H
#define Creature_H
#include <iostream>

using namespace std;

struct PositionC
{
	int x;
	int y;
};

class Creature
{
private:

	PositionC CreaturePos;
	char CreatureIcon = 'C';
	int CreatureBlood = 100;
	int CreatureAttack = 100;

public:

	Creature()
	{
		this->CreaturePos.x = 6;
		this->CreaturePos.y = 6;
		this->CreatureIcon = 'C';
	};

	//Set position
	void setPosC(PositionC pos);
	void setPosC(int x, int y);

	//Set icon
	void setIconC(char icon);

	//Set blood
	void setBloodC(int b);

	//Set attack
	void setAttackC(int a);

	//Get position
	PositionC getPosC(void);

	//Get icon
	char getIconC(void);

	//Get blood
	int getBloodC(void);

	//Get attack
	int getAttackC(void);

	//Whether the creature see the hero, cout the message, calculate the direction, and move relatively
	PositionC canSee(int x, int y, int xCreature, int yCreature);

	~Creature();

};
#endif		//Creature_H
