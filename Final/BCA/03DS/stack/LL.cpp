#include<iostream>
using namespace std;

template <class T>
class Stack{
    class Node{
        public:
        T data;
        Node *next;
        Node(T data){this->data=data;next=NULL;}
        Node(){data=0;next=NULL;}
    };

    Node *top;
    public:
    Stack(){top=NULL;}

    T push(T data){
        Node *n=new Node(data);
        if(n){
            n->next=top;
            top=n;
            return n->data;
        }
        return 0;
    }

    T pop(){
        T item=0;
        if(top){
            Node *temp=top;
            item=top->data;
            top=top->next;
            delete temp;
        }
        return item;
    }

    T peek(int pos){
        if(!top) return 0;

        Node *temp=top;
        for(int i=0;i<pos-1 && temp; i++) temp=temp->next;

        return temp ? temp->data : -1; 
    }
    T stackTop(){return top ? top->data : 0 ;}
    
    int isEmpty(){ return !top ? 1 : 0 ; }

    int isFull(){ 
        Node *temp=new Node();
        int res=temp ? 0:1;
        delete temp;
        return res; 
    }
    void display(){
        Node *temp=top;
        cout<<"Stack is ";
        while(temp){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        
        cout<<endl;
    }
};
// class Node {
//     public:
//     int data;
//     Node *next;
//     Node(int data){this->data=data;next=NULL;}
// };
// int main(){       
//     Stack <Node *>st;
//     for(int i=1;i<=10;i++) st.push(new Node(i));
//     st.display();
//     // int x=NULL;
//     return 0;
// }