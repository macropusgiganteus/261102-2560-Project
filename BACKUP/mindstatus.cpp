#include<iostream>
#include<ctime>
#include<string>


class Unit {
	string name;
	int hp;
	int hpmax;
	int attack;
	int def;
	public 
	int beattack(int);
	int upgrade(int,int);
	int attack(Unit &);
	
};

int Unit::beattack(int a){
	int damage=a-def;
	hp-=damage;
	return damage;
	
}

int Unit::attack(Unit &b){
	return beattack(attack);
}

int Unit::upgrade(int c,int d){
	
}
