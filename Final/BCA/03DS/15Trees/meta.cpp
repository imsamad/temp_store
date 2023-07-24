#include<iostream>
using namespace std;

int sqrt(int expo,int power){
    int sum=expo;
    if(power==0)return 1;
    for(int i=2;i<=power;i++) sum*=expo;
    return sum;
}

int log(int num){return 1;}

class Tree{
    public:
    long long int noOfTrees(int nodeNo, int labelled=0){
        // 2nCn/n+1
        /*
        Point to notes :- 
            a.) if no of node exceeds 10 have to declare long int. 
        */
        long long int a=1,b=1,deno=nodeNo+1;
        for(long long int i=2*nodeNo;i>nodeNo;i--){
            a=a*i;
            b=b*(i-nodeNo);
        }
        deno=nodeNo+1;
        long long int res=(a/b)/deno;
        if(labelled){
            for(int i=nodeNo;i>0;i--)res=res*i;
        }
        return res;
    }
    void fromHeightNodes(int height){
        cout<<"Min Nodes => "<<height+1<<", Max Nodes => "<<sqrt(2,height+1)-1<<", Strict Min Nodes => "<<height*2+1<<endl;
    }
    void fromNodesHeight(int nodes){
        cout<<"Max  Height"<<nodes-1<<", Min Height => "<<log(nodes+1)-1<<", Max Height Strict "<<(nodes-1)/2<<endl;
    }
    void leafIntenalNodes(int nodes){
        cout<<"Simple Tree => a.) With deg(0) =x ,then deg(2) x+1";
        cout<<"Strict Binary Trees a.) Internal Nodes x then , leaft nodes are x+1";
    }
};

int main(){
    Tree t;
    for(int i=2;i<=5;i++)
    t.fromHeightNodes(i);   
    
    return 0;
}