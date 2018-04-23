struct player{
	string name;
	int score=1;
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
    int dmg;
    bool T,ATK;
};


class Unit {
	public :
		player hero;
		string name;
		int hp;
		int hpmax;
		int atk;
		int def; 
		int beattack(int);
		int attack(Unit &);
		void SelectHero();
		void upgrade(int,Unit &);
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
	atk=rand()%10+20;
	def=rand()%10+5;
}




int Unit::beattack(int a){
	int damage=a-def;
	if(damage<=0) damage=0;
	hp-=damage;
	return damage;
	
}

int Unit::attack(Unit &b){
	return b.beattack(atk);
}

void Unit::SelectHero(){
    cout << "			-----------------------------cat------------------------------" << endl ;
    cout << "				[1]	hpmax = 99\t"  << "atk = 30\t" << "def = 20" << endl ;
    cout << "			---------------------------------------------------------------\n" ;
    cout << "			----------------------------kekko-----------------------------" << endl ;
    cout << "				[2]	hpmax = 75\t"  <<  "atk =25\t" << "def = 15" << endl ;
    cout << "			---------------------------------------------------------------\n" ;
    cout << "			-----------------------------dd-------------------------------" << endl ;
    cout << "				[3]	hpmax = 85\t"  <<  "atk =25\t" << "def = 20" << endl ;
    cout << "			---------------------------------------------------------------\n" ;
    string x ;
    while(1){
    	cout << "					Please select your hero : " ;
    	cin >> x ;
    	if(x=="1"){
    			hpmax = 99 ;
            	atk = 30 ;
            	def = 30 ;
            	break;
		} else if(x=="2"){
				hpmax = 75 ;
            	atk = 25 ;
            	def = 15 ;
            	break;
		} else if(x=="3"){
			 	hpmax = 85 ;
            	atk = 25 ;
            	def = 20 ;
            	break;
		} else {
			cout<<"						incorrect input"<<endl;
			continue;
		}
		
	}  
	hp=hpmax;
}

void Unit::upgrade(int s,Unit &p){
	string key;
	system("cls");
	cout<<"\n\n\n							STAGE"<<s<<endl;
	cout<<"\n			 	   <<<  HP : "<<p.hp<<" / "<<p.hpmax<<" >>>  ATK : "<<p.atk<<" DEF : "<<p.def<<endl;
	cout<<"\n				1.ATK +10   2.DEF +5   3.HPMAX +20  4.HEAL 20HP"<<endl;
	
	while(1){
    	cout << "\n					Press number to upgrade your hero : " ;
    	cin >> key ;
    	if(key=="1"){
    			atk+=10;
            	break;
		} else if(key=="2"){
				def+=5;
            	break;
		} else if(key=="3"){
			 	hpmax+=20;
            	break;
		} else if(key=="4"){
			hp+=20;
			if(hp > hpmax) hp=hpmax;
			break;
		}else{
			cout<<"						incorrect input"<<endl;
			continue;
		}	
	} 	
}
