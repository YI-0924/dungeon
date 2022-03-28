//Name:呂欣怡
//Date:March 12,2022
//Last Update:March 20,2022
//Problem statement: Trigger.

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<vector>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function
#include<time.h>
#include<string>

#include"Hero.h"
#include"Creature.h"
#include"Trigger.h"

#define SIZE 12

using namespace std;

int main() {

	vector< vector<char> > maze;
	char dir = 0;
	string act, bracket, num1, num2;
	int a, b;

	// ===== set hero ===== //
	PositionH heroPos;
	heroPos.x = 1;
	heroPos.y = 1;
	Hero hero;
	hero.setPosH(heroPos);
	//hero.setPosH(1, 1);
	hero.setIconH('h');
	hero.setBloodH(100);
	hero.setAttackH(1);
	hero.setExpH(0);

	// ===== set creature ===== //
	PositionC creaturePos;
	creaturePos.x = 6;
	creaturePos.y = 6;
	Creature creature;
	creature.setPosC(creaturePos);
	//creature.setPosC(6, 6);
	creature.setIconC('c');
	creature.setBloodC(100);
	creature.setAttackC(100);

	// ===== set trigger ===== //
	PositionT triggerPos;
	triggerPos.x = 6;
	triggerPos.y = 7;
	Trigger trigger;
	trigger.setIconT('t');
	trigger.setPosT(triggerPos);

	// ===== start ===== //
	hero.makeBoard(maze, &(heroPos.x), &(heroPos.y));
	hero.drawBoard(maze, heroPos.x, heroPos.y, creaturePos.x, creaturePos.y);

	do
	{
		getline(cin, act, ' ');
		getline(cin, bracket, '(');
		getline(cin, num1, ',');
		getline(cin, num2, ')');
		a = stoi(num1);
		b = stoi(num2);

		hero.modifyBoard(maze, &(heroPos.x), &(heroPos.y), &(creaturePos.x), &(creaturePos.y), dir, act, a, b);

		//cout << "icon: " << hero.getIconH() << "\t\t";
		//cout << "(x,y) = (" << hero.getPosH().x << "," << hero.getPosH().y << ")\n";
		cout << "The hero has HP : " << hero.getBloodH() << "\nThe hero is level : " << hero.getAttackH();
		cout << "\nThe hero has EXP : " << hero.getExpH() << "\nNeed 10 to level up\n";
		cout << "Every time you step on the trigger T, the hero get 10 EXP\n";

		creaturePos = creature.canSee(heroPos.x, heroPos.y, creaturePos.x, creaturePos.y);
		int blood = hero.getBloodH();
		if (heroPos.x == creaturePos.x && heroPos.y == creaturePos.y) 
		{
			blood -= 10;
			hero.setBloodH(blood);
		}
		if (blood == 0) {
			break;
		}
		creature.setPosC(creaturePos.x, creaturePos.y);
		hero.setPosH(heroPos.x, heroPos.y);
		int exp = hero.getExpH();
		hero.setExpH(trigger.addExp(heroPos, triggerPos, exp));
		exp = hero.getExpH();
		int attack = hero.getAttackH();
		if (exp % 10 == 0 && exp != 0) {
			cout << "level up!\n";
			attack++;
			hero.setAttackH(attack);
			hero.setExpH(0);
		}

	} while ( cin >> dir);

	cout << "Dead!\n";
	system("pause");

	return 0;
}
