struct player{
	string name;
	int score=0;
	float time=0;
};

struct variable{
	vector<string> name ;
    vector<int> score ;
    vector<float> time;
    string word,cmd;
	string status;
	char newtry;
    int R=0,stage=1,m=0;
    float timer;
    vector<string> monstername;
};


class Unit {
	public :
		player hero;
		string name;
		int hp=100;
		int hpmax=100;
		int atk;
		int def;
		int beattack(int);
		int upgrade(int,int);
		int attack(Unit &);	
		void namein(variable &,int,int );
		Unit();
};

void Unit::namein(variable &v,int i=2,int a=0){
	if(i!=2) name=v.monstername[a];
}

Unit::Unit(){
	srand(time(0));
	hpmax=rand()%100+100;
	hp=hpmax;
}




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