#include<windows.h>
#include"MMsystem.h"
#include<stdio.h>
struct idxloc{
	vector<int> idx1,idx2,idx3;
};

bool check_same_word(idxloc &loc,int wordloc,int stage){
	if(stage<3){
		for(int i=0;i<loc.idx1.size();i++){
		if(loc.idx1[i]==wordloc) return true;
		else return false;
	}
	}else if(stage<6){
		for(int i=0;i<loc.idx2.size();i++){
		if(loc.idx2[i]==wordloc) return true;
		else return false;
	}}
	else {
		for(int i=0;i<loc.idx3.size();i++){
		if(loc.idx3[i]==wordloc) return true;
		else return false;
	}
}
}

string randword(Words w,int &stage){
	while(1){
		int Ez=w.easyword.size();
	int Nm=w.medword.size();
	int Hd=w.hardword.size();
	srand(time(0));
	string text;	
	idxloc loc;
	int wloc;
	if(stage<10) wloc=rand()%Ez; 
	else if(stage<20) wloc=rand()%Nm;
	else if(stage<30) wloc=rand()%Hd;
	if(check_same_word(loc,wloc,stage)) continue;
	else{
		
		string word;
		string t;
		if(stage<10){
			word=w.easyword[wloc]; 
			loc.idx1.push_back(wloc);
			cout<< "\n\n\n"<<"				STAGE "<<stage<<"		>>  "<<word<<"  <<<"<<endl;
			cout<<"EASY"<<endl;
		} 
		else if(stage<20){
			word=w.medword[wloc];
			loc.idx2.push_back(wloc); 
			cout<< "\n\n\n"<<"				STAGE "<<stage<<"		>>  "<<word<<"  <<<"<<endl;
			cout<<"MEDIUM"<<endl;
		}
		else if(stage<30){
			word=w.hardword[wloc];
			loc.idx3.push_back(wloc); 
			cout<< "\n\n\n"<<"				STAGE "<<stage<<"		>>  "<<word<<"  <<<"<<endl;
			cout<<"HARD"<<endl;
		}
		return word;
	} 	
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
		system("cls");
		cout<<"\n"<<"					|||||| Thanks for playing!! ||||||"<<"				"<<endl;
		cout<<"\n"<<"	---------------------------------------------------------------------------------------------"<<endl;
		cout<<"\n"<<"	  RANK			PLAYER			 STAGE			TIME"<<endl;
		for(int i=0;i<N;i++){
			cout<<" 	  "<<" "<<i+1<<"  			"<<v.name[i]<<"	 		   "<<v.score[i]<<"			"<<v.time[i]<<" seconds"<<endl;
		}

		
	}
	else if(time<=5&&textAns==v.word){
		PlaySound(TEXT("correct1.wav"),NULL,SND_SYNC);
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
