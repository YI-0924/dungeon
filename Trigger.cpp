//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#include"Creature.h"
#include"Hero.h"
#include"Trigger.h"



//Set position
void Trigger::setPosT(PositionT pos)
{
	this->TriggerPos = pos;
}

void Trigger::setPosT(int x, int y)
{
	this->TriggerPos.x = x;
	this->TriggerPos.y = y;
}

void Trigger::setIconT(char icon) 
{
	this->TriggerIcon = icon;
}

int Trigger::addExp(PositionH posH, PositionT posT, int HeroExp)
{
	if (posH.x == posT.x && posH.y == posT.y)
	{
		HeroExp += 10;
	}
	return HeroExp;
}

Trigger::~Trigger()
{

}
