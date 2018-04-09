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
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<setw(8)<<"						Your words : ";
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
		cout<<"\n"<<"	  Rank			player			 score			time"<<endl;
		for(int i=0;i<N;i++){
			cout<<" 	  "<<" "<<i+1<<"  			"<<v.name[i]<<"	 		   "<<v.score[i]<<"			"<<v.time[i]<<endl;
		}

		
	}
	else if(time<=10&&textAns==v.word){
		p.hero.score++;
		cout<<"					    correct"<<" your time = "<<time<<"		"<<endl;
		cout<<"						Your score is "<<p.hero.score<<"				"<<endl;
		m.hp-=20;
	}
	else if(time>10) {
		cout<<"					fail"<<"	your time = "<<time<<"				"<<endl;
		cout<<"						Your score is "<<p.hero.score<<"				"<<endl;
	}
	else {
		cout<<"						    incorrect"<<endl;
		cout<<"						Your score is "<<p.hero.score<<"				"<<endl;
	}
	p.hero.time+=time;
	v.timer=time;
}			
