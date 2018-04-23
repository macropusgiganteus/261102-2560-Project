struct player{
	string name;
	int score= 1;
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
		void upgrade();
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
	hp-=damage;
	return damage;
	
}

int Unit::attack(Unit &b){
	return b.beattack(atk);
}

void Unit::SelectHero(){
	ifstream kit("charactor\\kitty.txt");
	string kitty;
	while(getline(kit,kitty)){
		cout<<"		"<<kitty<<endl;
	}
    cout << "\n"<<"	---------------------------Hello Kitty-------------------------" << endl ;
    cout << "		[1]	hpmax = 99\t"  << "atk = 30\t" << "def = 20" << endl ;
    cout << "	---------------------------------------------------------------\n\n" ;
    
    ifstream ku("charactor\\kuromi.txt");
	string kuromi;
	while(getline(ku,kuromi)){
		cout<<"		"<<kuromi<<endl;
	}
    cout << "	-----------------------------Kuromi----------------------------" << endl ;
    cout << "		[2]	hpmax = 75\t"  <<  "atk =25\t" << "def = 15" << endl ;
    cout << "	---------------------------------------------------------------\n" ;
    cout << "	-----------------------------Badzmaru--------------------------" << endl ;
    cout << "		[3]	hpmax = 85\t"  <<  "atk =25\t" << "def = 20" << endl ;
    cout << "	---------------------------------------------------------------\n\n" ;
    kit.close();
    
    int x ;
    cout << "					Please select your hero : " ;
    cin >> x ;
    switch(x){
        case 1 :{
            	hpmax = 65;
            	atk = 20 ;
            	def = 15 ;
	    	break ;
        }
        case 2 :{
           	hpmax = 35 ;
            	atk = 55;
            	def = 10  ;
		break ;
        }
        case 3 :{
            	hpmax =35 ;
            	atk = 35;
            	def = 30;
		break ;
        }
 }
 	hp=hpmax;
}

void Unit::upgrade(){
	int key;
	cout<<"1.Atk   2.Def   3.HP max  4.Heal"<<endl;
	cout<<"Pass number to upgrade your hero: "<<endl;
	cin>>key;
	switch(key){
		case 1:{
			atk+=50;
			break;
		}
		case 2:{
			def+=50;
			break;
		}
		case 3:{
			hpmax+=50;
			break;
		}
		case 4:{
			
			hp+=50;
			if(hp > hpmax) hp=hpmax;
			
			break;
		}
	}
}
