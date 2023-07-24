#include<iostream>
#include "../stack/LL.cpp"
using namespace std;
   
const int L=7;

int G[L+1][L+1]={
    {0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0},
    {0,1,0,1,0,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,0,1,0,1,0,0},
    {0,0,0,1,1,0,1,1},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0}
};

int visited[L+1]={0,0,0,0,0,0,0,0};

Stack <int>*s=new Stack<int>();

void visit(int i){
    cout<<i<<", ";
    visited[i]=1;
    s->push(i);
}

void ref(){
    // while(!s->isEmpty()) s->pop(); 
    for(int i=0;i<=L;i++) visited[i]=0;
}

void DFS(int i){
    if(visited[i]==0){
        visit(i);
        int u=s->pop();
        for(int i=1;i<=L;i++) 
            if(G[u][i]==1 && visited[i]==0 )  DFS(i);
    }
}

void DFSS(int i){
    ref();
    DFS(i);
    cout<<endl;
}

int main(){
    DFSS(1);        
    DFSS(2);        
    DFSS(3);        
    DFSS(4);        
    DFSS(5);        
    DFSS(6);        
    DFSS(7);        
    DFSS(8);        
    return 0;
}