#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Develop Class People in this header file. 

class People{
	string name;
	char gender;
	int age;
	int money;
	int energy;
	int happy;
	People *Father;
	People *Mother;
	vector<People *> Children;
	public:
		People(string,char,int);
		void show();
		void work(int);
		void play(int);
		void rest(int);
		void operator+( int);
		int operator-(People &);
		void operator>>(People &);
		void showFamily();
	
};
People::People(string n="Unknown",char g='F',int a=69){
	name=n;
	gender=g;
	age=a;
	money=0;
	energy=100;
	happy=50;
	Father=0;
	Mother=0;
}
void People::show(){
	cout<<"-------------------------------------"<<endl;
	cout<<"NAME : "<<name<<endl;
	cout<<"GENDER : ";
	if(gender=='m'||gender=='M') cout<<"MALE"<<endl;
	else cout<<"FEMALE"<<endl;
	cout<<"AGE : "<<age<<" years"<<endl;
	cout<<"MONEY : "<<money<<" Baht"<<endl;
	cout<<"ENERGY : "<<energy<<" %"<<endl;
	cout<<"HAPPINESS : "<<happy<<" %"<<endl;
	cout<<"-------------------------------------"<<endl;
}
void People::work(int wh){
	if(wh>0&&wh<energy) {
		int newmoney,newenergy,newhappy;
		newmoney=money+30*sqrt(happy)*(0.1*age+wh);
		newenergy=energy-wh;
		if(happy>wh/(1+0.0001*money)) {
			newhappy= happy - wh/(1+0.0001*money);
		}else{
			newhappy =0;
		}	
		money=newmoney;
		energy=newenergy;
		happy=newhappy;
	}
}
void People::play(int ph){
	if(ph>0&&ph<energy&&10*age*ph<=money){
		int newmoney,newenergy,newhappy;
		newmoney= money-10*age*ph;
		newenergy= energy-ph;
		newhappy=(100*ph+2*happy)/(ph+2);
		money=newmoney;
		energy=newenergy;
		happy=newhappy;
	}
}
void People::rest(int rh){
	if(rh>0){
		int newenergy,newhappy;
		int x=rand()%rh+1;
		int y=rand()%11;
		if((energy+x)>100) newenergy = 100;
		else newenergy=energy+x;
		if((happy+y)>100) newhappy=100;
		else newhappy=happy+y;
		energy=newenergy;
		happy=newhappy;
	}
}

void People::operator+(int N){
	 age+=N;
}

int People::operator-(People &P2){
	return age-P2.age;
}

void People::operator>>(People &P){
	Children.push_back(&P);
	if(gender=='M'||gender=='m') P.Father=this;
	else P.Mother=this;
}

void People::showFamily(){
	cout<<"-------------------------------------"<<endl;
	cout<<"NAME : "<<name<<endl;
	if(Father!=0 )cout<<"FATHER : "<<Father->name<<endl;
	if(Mother!=0)cout<<"MOTHER : "<<Mother->name<<endl;
	if(Children.size()!=0){
		cout<<"CHILDREN : ";
		for(int i=0;i<Children.size();i++)
		 if(i==0) cout<<Children[i]->name;
		 else cout<<", "<<Children[i]->name;
	}
	cout<<"\n-------------------------------------"<<endl;
	
}


