#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node *right;
    Node(int data){this->data=data;left=right=NULL;}
};             
int *leaf=0;
template <class t>
class Queue{

    t *arr;
    int last;
    int front;
    public:
    Queue(){ 
        last=front=0;
        arr=new t[100]; 
    }
    
    t  enqueue(t  data){
        // arr[last++]=data;
        return arr[last++]=data;; 
    }
    
    t  dequeue(){
        // t * x=arr[front];
        // front++;
        return arr[front++];
    }

    int isEmpty(){
        int flag=0;
        if(last == front || front > last) flag=1;
        return flag;
    }

    void display(){
        cout<<"Queue is :- \t";
        for(int i=front;i<last;i++){
            t * temp=arr[i];
            cout<<*temp<<" => ";
            // cout<<arr[i]<<" =>";
        }
        cout<<endl;
    }
};


template <class t>
class Stack{

    t *arr;
    int top;
    public:
    Stack(){ 
        top=-1;
        arr=new t[100]; 
    }
    t  push (t data){ 
        return arr[++top]=data;; 
    }
    t  pop(){ 
        return arr[top--];
    }
    int isEmpty(){
        return top<0;
    }
    void display(){
        cout<<"Stack is ";
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" =>";
        }
        cout<<endl; 
    }
};


class BiTree{
    Node *root;
    public:
    BiTree(){root=NULL;}
 
    void createTree(int data,int *arr){
        Queue <Node *>q;
        int i=0;
        Node *n=new Node(arr[i++]);
        root=n;
        q.enqueue(n);
        while(!q.isEmpty()){
            Node *temp=q.dequeue();

            int newItem=arr[i++];
            // cout<<"Enter left child of "<<temp->data<<"\t";
            // cin>>newItem;    
            if(newItem!=-1){
                Node *newNode=new Node(newItem);
                temp->left=newNode;
                q.enqueue(newNode);
            }        
            // cout<<"Enter right child of "<<temp->data<<"\t";
            // cin>>newItem;
            newItem=arr[i++];    
            if(newItem!=-1){
                Node *newNode=new Node(newItem);
                temp->right=newNode;
                q.enqueue(newNode);
            }        
        }
    }
 
    void preOrder(Node * node){ 
    if(node){        
        cout<<node->data<<" => ";
        preOrder(node->left);  
        preOrder(node->right); 
    } 
    }
    void rec_preOrder(){cout<<"Pre Order :- \t";preOrder(root);cout<<endl;}
    void inorder(Node * node){ 
        if(node){        
            inorder(node->left);  
            cout<<node->data<<" => ";
            inorder(node->right); 
        } 
    }
    void rec_inorder(){cout<<"In Order :- \t";inorder(root);cout<<endl;}
    void postOrder(Node * node){ 
    if(node){        
        postOrder(node->left);  
        postOrder(node->right); 
        cout<<node->data<<" => ";
    } 
    }
    void rec_postOrder(){cout<<"Post Order :- \t";postOrder(root);cout<<endl;}

    void it_preOrder(){
        Stack <Node *>s;
        Node *p=root;
        cout<<"Stack iter :- ";
        while(p || !s.isEmpty()){
            if(p){
                cout<<p->data<<" => ";
                s.push(p);
                p=p->left;
            } else {
                p=s.pop();
                p=p->right;
            }
        }
        cout<<endl;
    }
    
    void it_inOrder(){
         Stack <Node *>s;
         Node *p=root;
         cout<<"InOrder it :- ";
         while(p || !s.isEmpty()){
             if(p){
                 s.push(p);
                 p=p->left;
             }else{
                 p=s.pop();
                 cout<<p->data<<" =>  ";
                 p=p->right;
             }
         }
         cout<<endl;
     }
    
    void it_postOrder(){
        Stack <Node *>s;
        Node *p=root;
        long long int temp;
        cout<<"PreOrder It :- ";
        while(p || !s.isEmpty()){
            if(p){
                s.push(p);
                p=p->left;
            }else{
                temp=(long long int)s.pop();
                if(temp>0){
                   s.push((Node*)(-temp));
                   p=(Node *)temp;
                   p=p->right;
                }else{
                    Node *t=(Node *)(+temp);
                    cout<<t->data<<" =>  ";
                    p=NULL; 
                }
            }
        }
        cout<<endl;
    }
    
    void it_levelOrder(){
        Node *p=NULL;
        Queue <Node *>q;
        q.enqueue(root);
        cout<<"LevelOrder It :- ";
        while(!q.isEmpty()){
            p=q.dequeue();
            cout<<p->data<<" =>  ";
            if(p->left)q.enqueue(p->left);    
            if(p->right)q.enqueue(p->right);    
        }
        cout<<endl;
    }
   
    int Height(Node *node){
        if(!node) return 0;

        int lHeight,rHeight;    
        lHeight=Height(node->left);
        rHeight=Height(node->right);
        if(node->right && node->left) return lHeight+rHeight+1;
        return lHeight+rHeight;
        // from gfg
        // if(lHeight>rHeight) return lHeight+1;
        // return rHeight+1;

        // return !node ? -1 : lHeight>rHeight ? lHeight+rHeight+1 : lHeight+rHeight;
    }
    void rec_Height(){ cout<<"Rec Height"<<Height(root)<<endl; }
 
    int count(Node *node){
        // return !node ? 0 : count(node->left) + count(node->right) + 1;
        int x,y;
        if(node){
            x=count(node->left);
            y=count(node->right);
            return x+y+1;
        } else return 0;
    }
    void res_count(){  cout<<"Rec Count"<<count(root)<<endl;}
  
    void leafNode(Node *node){
        if(!node) return;
       
        if(!node->right && !node->left)  *leaf++;
        if(node->right)leafNode(node->right);
        if(node->left)leafNode(node->left);
        
    }
    void rec_leafNode(){leafNode(root);cout<<"LEaf Nodes are "<<*leaf<<endl;}

 
};
int main(){ 
    BiTree t;
   int arr[]={10,20,30,40,50,60,70,80,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  
    
    // t.createTree(10,arr);
    // t.it_preOrder();
    // t.rec_preOrder();
    // t.it_inOrder();
    // t.rec_inorder();
    // t.rec_postOrder();
    // t.it_postOrder();
    // t.it_levelOrder(); 
    // t.rec_Height();
    // t.res_count();
    // t.rec_leafNode();

   


    return 0;
}