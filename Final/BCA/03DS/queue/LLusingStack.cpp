#include<iostream>
#include "../stack/LL.cpp"
using namespace std;
template <class T>
class Queue{
    Stack <T>*S1,*S2;
    public:
    Queue(){S1=new Stack<T>();S2=new Stack<T>();}
    T enqueue(T data){
        return S1->push(data);
    }
    T dequeue(){
        if(S2->isEmpty())
            if(!S1->isEmpty())
                while(!S1->isEmpty()) 
                    S2->push(S1->pop());
            else return 0;
        return S2->pop();
    }
    int isEmpty(){return S1->isEmpty() && S2->isEmpty() ? 1 : 0 ; }
};             
// int main(){
//     Queue <int>*q=new  Queue<int>();         
//     for(int i=1;i<=20;i++) q->enqueue(i);
//     cout<<"Queue is :- "<<endl;
//     while(!q->isEmpty()) cout<<q->dequeue()<<" ,";
//     cout<<endl;

//     return 0;
// }