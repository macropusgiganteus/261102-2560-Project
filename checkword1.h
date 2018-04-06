using namespace std;

bool check_same_word(int N,int wordloc,vector<int> idx){
	for(int i=0;i<N;i++){
		if(idx[i]==wordloc) return true;
		else return false;
	}
}

string randword(Words w,int stage=0){
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
		cout<< "\n"<<"						>>  "<<wordEz <<"  <<"<<endl;
		return wordEz;
	} 	
}

void inputword(string w,float &t,string &cmd,player &p){
	float time;
	string textAns;
	clock_t start,End;
	start=clock();
	cout<<"\n"<<setw(8)<<"						Your words : ";
	cin>>textAns;
	cmd=textAns;
	End=clock();
	time=((float)(End-start)/CLOCKS_PER_SEC)+0.02;
	cout<<fixed<<setprecision(3);
	if(time>10) {
		cout<<"					fail"<<"	your time = "<<time<<"				"<<endl;
		cout<<"						Your score is "<<p.score<<"				"<<endl;
	}
	else if(time<=10&&textAns==w){
		p.score++;
		cout<<"					    correct"<<" your time = "<<time<<"		"<<endl;
		cout<<"						Your score is "<<p.score<<"				"<<endl;	
		
	}
	else if(textAns=="exit") {
		cout<<"\n"<<"						Thanks for playing!!"<<"				"<<endl;
		cout<<"\n"<<"	---------------------------------------------------------------------------------------------"<<endl;
		cout<<"\n"<<"	  Rank			player			 score			time"<<endl;
		cout<<" 	  "<<" 1"<<"  			"<<p.name<<"	 		   "<<p.score<<"			"<<p.time<<endl;
	}
	else {
		cout<<"						    incorrect"<<endl;
		cout<<"						Your score is "<<p.score<<"				"<<endl;
	}
	p.time+=time;
	t=time;
}			
