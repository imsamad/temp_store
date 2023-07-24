#include<iostream>
#include "LL.cpp"
using namespace std;

int isBalance(char *exp){
    Stack <char>*st=new Stack<char>(); 

    for(int i=0; exp[i] ;i++){ 
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') st->push(exp[i]);
        else if(exp[i]==')'  || exp[i]=='}' || exp[i]==']'){
            if(st->isEmpty()){ return 0;}
            st->pop();
        }
    }
    
    return st->isEmpty() ? 1 : 0 ;
} 

int main() {
    string arr="((a+b)+(c+d))";
    string arr2="{([a+b]*[c+d])/e}";

    cout<<"IsBalance => "<<isBalance(&arr2[0])<<endl;

    return 0;
}