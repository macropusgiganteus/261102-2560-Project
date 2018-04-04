#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

bool check_same_word(int N,int same,vector<int> idx){
	for(int i=0;i<N;i++){
		if(idx[i]==same) return true;
		else return false;
	}
}

int main(){
	
	ifstream wordBasic("word_basic.txt");
	string word1;
	vector<string> easy_word;
	while(getline(wordBasic,word1)){
		easy_word.push_back(word1);
	}
	wordBasic.close();
	
	ifstream wordNormal("word_normal.txt");
	string word2;
	vector<string> normal_word;
	while(getline(wordNormal,word2)){
		normal_word.push_back(word2);
	}
	wordNormal.close();
	
	ifstream wordHard("word_hard.txt");
	string word3;
	vector<string> hard_word;
	while(getline(wordHard,word3)){
		hard_word.push_back(word3);
	}
	wordHard.close();
	
	int Ez=easy_word.size();
	int Nm=normal_word.size();
	int Hd=hard_word.size();

	while(1){
	srand(time(0));
	string text;
	
	while(1){
		vector<int> idx;
		int d=rand()%Ez;
		if(check_same_word(idx.size(),d,idx)){
			continue;
		}else{
			
			idx.push_back(d);	
		
		string wordEz=easy_word[d];
		cout<< wordEz <<endl;
		cout<<"--------------------------------------------------------\n";
		cin>>text;
		if(text==wordEz){
			cout<<"--------------------------------------------------------\n";
			cout<<"correct!!!!\n";
			cout<<"--------------------------------------------------------\n";
			
			continue;	
		}
		else{
			cout<<"fail!!!!\n";
			break;
		} 
		}
		
		
	}
	break;

//stage2	
	while(1){
		vector<int> idx;
		int d=rand()%Nm;
		if(check_same_word(idx.size(),d,idx)){
			continue;
		}else{
		idx.push_back(d);	
		string wordNm=normal_word[d];
		cout<< wordNm <<endl;
		cout<<"--------------------------------------------------------\n";
		cin>>text;
		if(text==wordNm){
			cout<<"--------------------------------------------------------\n";
			cout<<"correct!!!!\n";
			cout<<"--------------------------------------------------------\n";
			
			continue;	
		}
		else{
			cout<<"fail!!!!\n";
			break;
		} 
	}
	}
	break;
	
//stage3
		while(1){
		vector<int> idx;
		int d=rand()%Hd;
		if(check_same_word(idx.size(),d,idx)){
			continue;
		}else{
		idx.push_back(d);	
		
		string wordHd=hard_word[d];
		cout<< wordHd <<endl;
		cout<<"--------------------------------------------------------\n";
		cin>>text;
		if(text==wordHd){
			cout<<"--------------------------------------------------------\n";
			cout<<"correct!!!!\n";
			cout<<"--------------------------------------------------------\n";
			
			continue;	
		}
		else{
			cout<<"fail!!!!\n";
			break;
		} 

	
	}
	break;
	}
}
	

}

		

