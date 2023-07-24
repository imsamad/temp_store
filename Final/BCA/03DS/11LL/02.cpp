#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){data=0;next=NULL;}
    Node(int data){this->data=data;next=NULL;}
};
class LL{
    Node *root;
    Node *last;
    int length;
    public:
    LL(){root=last=NULL;length=0;}
    void display(){
        Node *temp=root;
        cout<<"Linked List is:- \t";
        while(temp){
            cout<<temp->data;
            if(temp->next)cout<<" =>";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAfter(int item,int pos=-1){
        Node *n=new Node(item);
        // If no value is passed
        if(pos<-1 || pos > length){
            cout<<endl<<"Invalid position ,re-type \t";
            cin>>pos;
            if(pos<-1){cout<<endl<<"Aborting..."; return;}
        }
        
        if(pos==-1) pos=length;

        if(pos==0){
            // It works even if length is 0.
            n->next=root;
            root=n;
            if(length==0)last=n;
            length++;
        } 
        // If node to append at last.
        else if(pos==length){
            last->next=n;
            last=n;
            length++;
        }
        else if(pos>0){
            Node *temp=root;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            n->next=temp->next;
            temp->next=n;    
            length++;
        }
    }
    void insertBefore(int key,int pos){
        if(pos<=0){
            cout<<endl<<"Invalid position ,re-type \t";
            cin>>pos;
            if(pos<=0){cout<<endl<<"Aborting..."; return;}
        }

        insertAfter(key,pos-1);
    }
    void insertAt(int key,int pos){
        if(pos<0){
            cout<<endl<<"Invalid position ,re-type \t";
            cin>>pos;
            if(pos<=0){cout<<endl<<"Aborting..."; return;}
        }

    }
};

int main(){
    LL l;
    for(int i=1;i<=10;i++)l.insertAfter(i*10); 
    l.insertBefore(1111,1);
    l.insertBefore(2222,2);
    // l.insertBefore(3333,-1);
    // l.insertBefore(4444,0);
    l.display(); 
    return 0;
}