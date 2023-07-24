#include<iostream>
#include "LL.cpp"
using namespace std;

int pre(char x){
    return x == '+' || x == '-' ? 1 : x== '*' || x=='/' ? 2 : 0;  
}

int isOperand(char x){
    return x=='+' || x=='-' || x=='*' || x=='/' ? 0 : 1;
}


char * toPost(char * inFix){
    int i=0,j=0; while(inFix[i]) i++;
    char * postFix=new char[i+1];

    Stack <char>*st=new Stack<char>();

    i=0;
    while(inFix[i]){
        if(isOperand(inFix[i]))
            postFix[j++]=inFix[i++];
        else {
            if(pre(inFix[i]) > pre(st->stackTop()))
                st->push(inFix[i++]);
            else 
                postFix[j++]=st->pop();
        }
    }
    while(!st->isEmpty()) postFix[j++]=st->pop();

    // postFix[j]='\0';
    return postFix;
}

int evaluate(char *postFix){
    Stack <int>*st=new Stack<int>();
    for(int i=0;postFix[i];i++){
        if(isOperand(postFix[i])){
            // cout<<"Index "<<i<<" ,Pushing "<<postFix[i]<<endl;
            st->push(postFix[i]-'0');

        }else{
            int b=st->pop(),a=st->pop(),res;
            switch(postFix[i]){
                case '+':res=a+b; break;
                case '-':res=a-b; break;
                case '*':res=a*b; break;
                case '/':res=a/b; break;
            }
            //  cout<<"a= "<<a<<" "<<postFix[i]<<" b= "<<b<<" Result = "<<res<<endl;
            st->push(res); 
        }
    }
    return st->pop();
}

int main() { 
    string inFix="3*5+6/2-4";
    char *postFix=toPost(&inFix[0]);
    cout<<"InFix "<<inFix<<endl;
    cout<<"PostFix "<<postFix<<endl;

    int evl=evaluate(postFix);
    cout<<"Evaluate "<<evl<<endl;
    // char x='3';
    // int a=(char)x;
    // cout<<a;    
    return 0;
}