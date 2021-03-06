bool check_same_word(int N,int wordloc,vector<int> idx){
	for(int i=0;i<N;i++){
		if(idx[i]==wordloc) return true;
		else return false;
	}
}

string randword(Words w,int &stage){
	int Ez=w.easyword.size();
	int Nm=w.medword.size();
	int Hd=w.hardword.size();
	srand(time(0));
	string text;	
	vector<int> idx;
	int wloc=rand()%Ez;
	if(check_same_word(idx.size(),wloc,idx)) return "used";
	else{
		idx.push_back(wloc);	
		string wordEz=w.easyword[wloc];
		
		cout<< "\n\n\n"<<"				STAGE "<<stage<<"		>>  "<<wordEz <<"  <<"<<endl;
		return wordEz;
	} 	
}

void inputword(variable &v,Unit &p,Unit &m){
	float time;
	string textAns;
	clock_t start,End;
	start=clock();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
	cout<<"\n				<<<  HP : "<<p.hp<<" / "<<p.hpmax<<" >>>  ATK : "<<p.atk<<" DEF : "<<p.def<<endl;
	cout<<setw(8)<<"						Your words : ";
	cin>>textAns;
	v.cmd=textAns;
	End=clock();
	time=((float)(End-start)/CLOCKS_PER_SEC)+0.02;
	cout<<fixed<<setprecision(3);
	if(textAns=="exit") {
		keepscore(v.score,p.hero.score);
		keeptime(v.time,p.hero.time);
		sortRank(v);
		int N=v.name.size();
		cout<<"\n"<<"					|||||| Thanks for playing!! ||||||"<<"				"<<endl;
		cout<<"\n"<<"	---------------------------------------------------------------------------------------------"<<endl;
		cout<<"\n"<<"	  RANK			PLAYER			 STAGE			TIME"<<endl;
		for(int i=0;i<N;i++){
			cout<<" 	  "<<" "<<i+1<<"  			"<<v.name[i]<<"	 		   "<<v.score[i]<<"			"<<v.time[i]<<endl;
		}

		
	}
	else if(time<=5&&textAns==v.word){
		cout<<"					    correct"<<" your time = "<<time<<"		"<<endl;
		cout<<"						Your score is "<<p.hero.score<<"				"<<endl;
		v.T=true;
		v.dmg=p.attack(m);
	}
	else if(time>5) {
		cout<<"					fail"<<"	your time = "<<time<<"				"<<endl;
		cout<<"						Your score is "<<p.hero.score<<"				"<<endl;
		v.T=false;
		v.dmg=m.attack(p);
	}
	else {
		cout<<"						    incorrect"<<endl;
		cout<<"						Your score is "<<p.hero.score<<"				"<<endl;
		v.T=false;
		v.dmg=m.attack(p);
	}
	v.ATK=true;
	p.hero.time+=time;
	v.timer=time;
}			
