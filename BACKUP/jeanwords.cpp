#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;
void keepname(vector<string> &,string ) ;
void keepword1(vector<string> &,string ) ;
void keepword2(vector<string> &,string ) ;
void keepword3(vector<string> &,string ) ;
int main(){
    vector<string> name ;
    vector<string> easyword ;
    vector<string> medword ;
    vector<string> hardword ;
    string N ;
    cout << "Enter your name : " ;
    cin >> N ;
    keepname(name,N) ;
  cout << name[0] ;
    ifstream word1("easywords.txt") ;
    string s ;
    while(getline(word1,s)){
        keepword1(easyword,s) ;
    }
    ifstream word2("medwords.txt") ;
    string s2 ;
    while(getline(word2,s2)){
        keepword2(medword,s2) ;
    }
    ifstream word3("hardwords.txt") ;
    string s3 ;
    while(getline(word3,s3)){
        keepword3(hardword,s3) ;
    }
    word1.close() ;
    word2.close() ;
    word3.close() ;
    return 0 ;
}
void keepname(vector<string> &name,string N){
    name.push_back(N) ;
}
void keepword1(vector<string> &easyword,string s){
    easyword.push_back(s) ;
}
void keepword2(vector<string> &medword,string s2){
    medword.push_back(s2) ;
}
void keepword3(vector<string> &hardword,string s3){
    hardword.push_back(s3) ;
}
