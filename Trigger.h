//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#ifndef Trigger_H
#define Trigger_H
#include <iostream>

using namespace std;

struct PositionT
{
	int x;
	int y;
};

class Trigger
{
private:

	PositionT TriggerPos;
	char TriggerIcon = 'T';

public:

	Trigger()
	{
		this->TriggerIcon = 'T';
		this->TriggerPos.x = 6;
		this->TriggerPos.y = 7;
	}

	//Set position
	void setPosT(PositionT pos);
	void setPosT(int x, int y);

	//Set icon
	void setIconT(char icon);

	//Exp
	int addExp(PositionH posH, PositionT posT, int HeroExp);

	~Trigger();
};

#endif
