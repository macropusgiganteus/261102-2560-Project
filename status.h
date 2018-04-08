struct player{
	string name;
	int score=0;
	float time=0;
};


class Unit {
	public :
		player hero;
		int hp;
		int hpmax;
		int atk;
		int def;
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
	return beattack(atk);
}

int Unit::upgrade(int c,int d){
	
}
