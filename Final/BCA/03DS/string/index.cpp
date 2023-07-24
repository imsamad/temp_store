#include<iostream>
using namespace std;
#pragma GCC diagnostic ignored "-Wwrite-strings"


int main(){
    char charA='A';
    char charArrSimple[]={'A','b','d','u','s','S','a','m','a','d'};
    char charArrDirect[]="AbdusSamad";
    cout<<"Size of Simple Char array => "<<sizeof charArrSimple<<endl;
    cout<<"Size of Direct Char array => "<<sizeof charArrDirect<<endl;

    // This would create immutable array of char in heap  ;
    // char *name="Abdus Samad";
    char *name="Abdus Samad";
    cout<<"Size ofpointer "<<sizeof name<<endl;
    cout<<"Before Name => "<<name<<endl;
    //Can't mutatae a string initaited using pointer char
    // name[0]='X';
    // cout<< 


    return 0;
}