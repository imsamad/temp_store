#include<iostream>
#include "../queue/LLusingStack.cpp"
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

Queue <int>*q=new Queue<int>();

void visit(int i){
    cout<<i<<", ";
    visited[i]=1;
    q->enqueue(i);
    q->enqueue(i);
}

void ref(){
    while(!q->isEmpty()) q->dequeue(); for(int i=0;i<=L;i++) visited[i]=0;
}

void BFS(int i){
    ref();

    visit(i);
    while(!q->isEmpty()){
        int u=q->dequeue();
        for(int i=1;i<=L;i++){
            if(G[u][i]==1 && visited[i]==0 )
                    visit(i);
            
        }    
    }
    cout<<endl;
}
int main(){
    BFS(1);        
    BFS(2);        
    BFS(3);        
    BFS(4);        
    BFS(5);        
    BFS(6);        
    BFS(7);        
    // BFS(8);        
    return 0;
}