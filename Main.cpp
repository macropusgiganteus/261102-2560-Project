using namespace std;
#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include<cstdlib>
#include <algorithm>
#include<iomanip>
#include"status.h"
#include "infotovector.h"
#include "checkword1.h"


int main(){
	Words allword;
	variable v;
	keepinfo(allword) ; 
	do{
		Unit typer;
		cout<<"	---------------------------------------------------------------------------------------------"<<endl;
    	cout<<"						Enter your name : " ;
    	cin >> typer.hero.name ;
    	keepname(v.name,typer.hero.name);
    //start typing
	    do{
		    v.word=randword(allword);
			inputword(v,typer);	
			if(v.cmd=="exit"||v.cmd=="newtry") break;
		}while(v.status!="dead");
		cout<<"\n"<<"					Do you want to try again? Y/N : ";
		cin>>v.newtry;
		v.newtry=toupper(v.newtry);
		v.R++;
			cout<<"	---------------------------------------------------------------------------------------------"<<endl;
	}while(v.newtry!='N');
	
	return 0;
}

