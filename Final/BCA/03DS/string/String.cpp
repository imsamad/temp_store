#include<iostream>
using namespace std;

class String {
    string str;
    public:
    String(string str){
        this->str=str;
    }
    String(){str="\0";}
    void display(){
        cout<<"String is :- "<<str<<endl;
    }
    int length();
    string toUppercase();
    string toLowercase();
    string toggleCase();

    void vowelsConsonantsWords();
    int validateString(){
        // b/w a to z
        //  b/w A to Z
        //  b/w 0 to 9

    }

    string reverse();
    int isPallindrome();

    void duplicate();

    int isAnagram();

};             
int main(){
       
    String s("AbdusSamad");

    s.display(); 
    return 0;
}
