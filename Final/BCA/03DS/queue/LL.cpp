#include<iostream>
using namespace std;

template <class T>
class Queue{
    class Node{
        public:
        T data;
        Node *next;
        Node(){next=0;data=0;}
        Node(T data){this->data=data;next=NULL;}

    };
    Node *front,*rear;
    public:
    Queue(){front=rear=NULL;}
    T enqueue(T data){
        Node *n=new Node(data);
        
        if(!front){ rear=front=n; return n->data; }
        rear->next=n;
        rear=n;
        
        return n->data;
    }
    T dequeue(){
        if(!front) return 0;
        Node *temp=front;
        front=front->next;
        
        int tempDate=temp->data;
        delete temp;
        return tempDate;
    }
    T first(){ return first ? first->data : 0; }
    T last(){ return rear ? rear->data : 0 ;}
    int isEmpty(){return front==NULL;}
    int isFull(){ Node *temp=new Node(); return !temp? 1 : 0; }
    void display(){
        Node *temp=front;
        cout<<"Queue is => ";
        while(temp ) {cout<<temp->data<<"\t"; temp=temp->next; }
        cout<<endl;
    }
};

int main(){
    Queue <int>*q=new Queue<int>();
    for(int i=1;i<=20;i++) q->enqueue(i); 
    while(!q->isEmpty()) cout<<q->dequeue()<<"\t"; 
    cout<<endl;
    return 0;
}