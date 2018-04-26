#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream print("cinnamonroll.txt"); 
	string text;
	while(getline(print,text)) {
		cout<<text<<endl;
																	
	}
	print.close();
	
	return 0;
}

