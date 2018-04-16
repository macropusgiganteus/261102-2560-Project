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
	keepinfo(allword,v) ; 
	do{
		Unit typer;
		system("cls");
		cout<<"	---------------------------------------------------------------------------------------------"<<endl;
    	cout<<"						Enter your name : " ;
    	cin >> typer.hero.name;
    	cout<<"\n\n\n\n"<<endl;
    	keepname(v.name,typer.hero.name);
    	//typer.SelectHero();
    //start typing
    do{
    	//if(v.stage%5==0) typer.upgrade();
    	Unit Monster;
    	Monster.namein(v,1,v.m);
    	do{
    		system("cls");
    		cout<<"	---------------------------------------------------------------------------------------------"<<endl;
    		cout<<"\n						<> Monster : "<<Monster.name<<"<>"<<endl;
			cout<<"						 <> HP "<<Monster.hp<<" / "<<Monster.hpmax<<" <>"<<endl;
    		cout<<"\n						<<< Your HP "<<typer.hp<<" / "<<typer.hpmax<<" >>>"<<endl;
		    v.word=randword(allword,v.stage);
			inputword(v,typer,Monster);	
			if(v.cmd=="exit"||v.cmd=="newtry") break;
		}while(Monster.hp>0);
		if(v.cmd=="exit"||v.cmd=="newtry") break;
		v.stage++;
		v.m++; 		
		v.R++;
	}while(v.status!="dead");
    	
		cout<<"\n"<<"					Do you want to try again? Y/N : ";
		cin>>v.newtry;
		v.newtry=toupper(v.newtry);

			cout<<"	---------------------------------------------------------------------------------------------"<<endl;
	}while(v.newtry!='N');
	
	return 0;
}

