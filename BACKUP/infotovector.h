#include <fstream>



void keepname(vector<string> &name,string N){
    name.push_back(N) ;
}
void keepword(vector<string> &word,string w){
    word.push_back(w) ;
}

void keepscore(vector<int> &score,int s){
	score.push_back(s) ;
}
void keeptime(vector<float> &time,float t){
	time.push_back(t) ;
}

struct Words{
	vector<string> easyword ;
    vector<string> medword ;
    vector<string> hardword ;
};


void keepinfo(Words &w,variable &v){
	ifstream Monster("monstername.txt");
	string mon;
	while(getline(Monster,mon)){
    	string ws;
    	int start=0;
    	int end=mon.find_first_of(" ");
    	ws=mon.substr(start,end-start);
        keepword(v.monstername,mon) ;
    }
    ifstream word1("easywords.txt") ;
    string s ;
    while(getline(word1,s)){
    	string ws;
    	int start=0;
    	int end=s.find_first_of(" ");
    	ws=s.substr(start,end-start);
        keepword(w.easyword,ws) ;
    }
    ifstream word2("medwords.txt") ;
    string s2 ;
    while(getline(word2,s2)){
    	string ws;
    	int start=0;
    	int end=s2.find_first_of(" ");
    	ws=s2.substr(start,end-start);
        keepword(w.medword,ws) ;
    }
    ifstream word3("hardwords.txt") ;
    string s3 ;
    while(getline(word3,s3)){
    	string ws;
    	int start=0;
    	int end=s.find_first_of(" ");
    	ws=s3.substr(start,end-start);
        keepword(w.hardword,ws) ;
    }
    word1.close() ;
    word2.close() ;
    word3.close() ;
    Monster.close() ;
}

void sortRank(variable &v){
	for(int i=0;i<v.score.size()-1;i++){
		if(v.score[i]<v.score[i+1]) {
			swap(v.score[i],v.score[i+1]);
			swap(v.name[i],v.name[i+1]);
			swap(v.time[i],v.time[i+1]);
		}
		if(v.score[i]==v.score[i+1]&&v.time[i]>v.time[i+1]){
			swap(v.score[i],v.score[i+1]);
			swap(v.name[i],v.name[i+1]);
			swap(v.time[i],v.time[i+1]);
		}
	}
}




