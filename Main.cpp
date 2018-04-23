using namespace std;

#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include<cstdlib>
#include <algorithm>
#include<iomanip>
#include<fstream>
#include"status.h"
#include "infotovector.h"
#include "checkword1.h"


int main(){
	Words allword; 
	variable v;
	keepinfo(allword,v) ;
	ifstream fence("charactor\\fence.txt");
	string fence1;
	while(getline(fence,fence1)){
	
		cout<<"    "<<fence1<<fence1<<fence1<<fence1<<fence1<<fence1<<fence1<<endl;
	}
	fence.close();
		cout<<"\n"; 
	ifstream name("charactor\\name.txt");
	string namegame;
	while(getline(name,namegame)){
	
		cout<<"				"<<namegame<<endl;
	}
	cout<<endl;
	
	ifstream fences("charactor\\fence.txt");
	while(getline(fences,fence1)){
	
		cout<<"    "<<fence1<<fence1<<fence1<<fence1<<fence1<<fence1<<fence1<<endl;
	}
	fence.close();
	
	ifstream st("charactor\\start.txt");
	string st1;
	while(getline(st,st1)){
	
		cout<<"  		       "<<st1<<endl;
	}
	st.close();
	
	cin.get();
	do{
		Unit typer;
		system("cls");
		for(int i=0;i<422;i++){
			cout<<"o";
			
			}
		
		cout<<endl;
		cout<<"												...START GAME...\n"<<endl; 
    	cout<<"												ENTER YOUR NAME : " ;
    	cin >> typer.hero.name;
    	cout<<"\n\n\n\n"<<endl;
    	keepname(v.name,typer.hero.name);
    	typer.SelectHero();
    //start typing
    do{
    	if(v.stage%5==0) typer.upgrade();
    	Unit Monster;
    	Monster.namein(v,1,v.m);
    	do{
    		system("cls");
    		cout<<"---------------------------------------------------------------------------------------------"<<endl;
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
		cin>>v.newtry;
		v.newtry=toupper(v.newtry);

			cout<<"	---------------------------------------------------------------------------------------------"<<endl;
	}while(v.newtry!='N');
	return 0;
}
