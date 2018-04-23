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
    	typer.SelectHero();
    //start typing
    do{
    	if(v.stage%2==0) typer.upgrade(v.stage,typer);
    	Unit Monster;
    	Monster.namein(v,1,v.m);
    	do{
    		system("cls");
    		cout<<"	---------------------------------------------------------------------------------------------"<<endl;
    		if(v.ATK){
    			if(v.T) cout<<"				You attacked "<<Monster.name<<" with "<<v.dmg<<" damage"<<endl;
    			else cout<<"				You are attacked by "<<Monster.name<<" with "<<v.dmg<<" damage"<<endl;
			}
    		
    		cout<<"	---------------------------------------------------------------------------------------------"<<endl;
    		cout<<"\n						<> Monster : "<<Monster.name<<"<>"<<endl;
			cout<<"\n				<<<  HP : "<<Monster.hp<<" / "<<Monster.hpmax<<" >>>  ATK : "<<Monster.atk<<" DEF : "<<Monster.def<<endl;
		    v.word=randword(allword,v.stage);
			inputword(v,typer,Monster);	
			if(typer.hp<=0) break;
			if(v.cmd=="exit"||v.cmd=="newtry") break;
		}while(Monster.hp>0);
		if(v.cmd=="exit"||v.cmd=="newtry") break;
		v.stage++; typer.hero.score++;
		v.m++; 		
		v.R++;
	}while(1);
		cout<<"\n"<<"					Do you want to try again? Y/N : ";	
			while(1){
			cin>>v.newtry;
			v.newtry=toupper(v.newtry);
			if(v.newtry=='Y'||v.newtry=='N') break;
		}
		v.stage=1;
			cout<<"	---------------------------------------------------------------------------------------------"<<endl;
	}while(v.newtry!='N');
	return 0;
}


