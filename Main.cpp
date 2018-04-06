#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include<cstdlib>
#include <algorithm>
#include<iomanip>
#include "infotovector.h"
#include "checkword1.h"
using namespace std;


int main(){
	vector<string> name ;
    vector<int> score ;
    player typer;
    string word,cmd;
	string status="alive";
    Words allword;
    float timer;
	keepinfo(allword) ; 
	cout<<"	---------------------------------------------------------------------------------------------"<<endl;
    cout<<"						Enter your name : " ;
    cin >> typer.name ;
    keepname(name,typer.name);
    //start typing
    do{
	    word=randword(allword);
		inputword(word,timer,cmd,typer);	
		if(cmd=="exit") break;
	}while(status!="dead");
	cout<<"	---------------------------------------------------------------------------------------------"<<endl;
	return 0;
}

