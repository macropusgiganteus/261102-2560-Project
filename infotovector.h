#include <fstream>
using namespace std;

void keepname(vector<string> &name,string N){
    name.push_back(N) ;
}
void keepword(vector<string> &word,string s){
    word.push_back(s) ;
}

struct Words{
	vector<string> easyword ;
    vector<string> medword ;
    vector<string> hardword ;
};

struct player{
	string name;
	int score=0;
	float time=0;
};

void keepinfo(Words &w){
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
    	ws=s.substr(start,end-start);
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
}




