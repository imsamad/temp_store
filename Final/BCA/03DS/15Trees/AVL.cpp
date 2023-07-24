#include<iostream>
using namespace std;

class Node{
    public:
    int data,height;
    Node *right,*left;
    Node(){right=left=NULL;height=data=0;}
    Node(int data){right=left=NULL;this->data=data;height=0;}
    Node(int data,int height){right=left=NULL;this->data=data;this->height=height;}
};

class AVL{  
    Node *root;
    public:
    AVL(){root=NULL;}
    void rec_preOrder(Node *node){
        if(node){
            cout<<node->data<<" ,";
            rec_preOrder(node->left);
            rec_preOrder(node->right);
        }
    }
    void rec_inOrder(Node *node){
        if(node){
            rec_inOrder(node->left);
            cout<<node->data<<" ,";
            rec_inOrder(node->right);
        }
    }
    void rec_postOrder(Node *node){
        if(node){
            rec_postOrder(node->left);
            cout<<node->data<<" ,";
            rec_postOrder(node->right);
        }
    }
    void preorder(){ cout<<"PreOrder is ";rec_preOrder(root);cout<<endl; }
    void inorder(){ cout<<"InOrder is ";rec_inOrder(root);cout<<endl; }
    void postorder(){ cout<<"PostOrder is ";rec_postOrder(root);cout<<endl; }

    int NodeHeight(Node *p){
        // cout<<"Height run"<<endl;
        int leftHeight= p && p->left ? p->left->height:0,
            rightHeight= p && p->right ? p->right->height:0;

        return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
    }

    int BalanceFactor(Node *node){
        int leftHeight= node && node->left ? node->left->height:0,
            rightHeight= node && node->right ? node->right->height:0;
        
        return leftHeight-rightHeight;
    }

    Node * rec_insert(Node *node,int data){
        // cout<<"Rec insrt"<<endl;
        if(!root) return root=new Node(data,1);  
        if(!node) return new Node(data,1); 
        // cout<<"Rec insert 2"<<endl;
        if(data < node->data) node->left=rec_insert(node->left , data);
        else if(data > node->data) node->right=rec_insert(node->right , data);
 
        node->height=NodeHeight(node);

        if(BalanceFactor(node) == 2 && BalanceFactor(node->left) == 1) return LLRoation(node);
        else if(BalanceFactor(node)==2 && BalanceFactor(node->left)==-1) return LRRoation(node);
        // else if(BalanceFactor(node)==-2 && BalanceFactor(node->right)==-1) return RRRoation(node);
        // else if(BalanceFactor(node)==-2 && BalanceFactor(node->right)==1) return RLRoation(node);
        
        return node;
    }
    void insert(int key){ rec_insert(root,key);}
    Node *LLRoation(Node *node){
        cout<<"I run"<<node->data;
        Node *newRoot=node->left,*temp=node->left->right;

        newRoot->right=node;
        node->left=temp;      

        newRoot->height=NodeHeight(newRoot);
        node->height=NodeHeight(node);

        if(root==node) root=newRoot;
        cout<<" ,Newroot "<<newRoot->data<<endl;
        return newRoot;
    }
    Node *LRRoation(Node *node){
        cout<<"LR Run"<<endl;
        Node * nodeL=node->left;
        Node *newRoot=nodeL->right;

        nodeL->right=newRoot->left;
        node->left=newRoot->right;

        newRoot->left=nodeL;
        newRoot->right=node;


        // Node *newRoot=node->left->right;
        // Node *tempL=newRoot->left,*tempR=newRoot->right;

        // newRoot->left=node->left;
        // newRoot->right=node->right;
        // newRoot->left->right=tempL;
        // newRoot->right->left=tempR;

        
        newRoot->height=NodeHeight(newRoot);
        nodeL->height=NodeHeight(nodeL);
        node->height=NodeHeight(node);

        if(node==root)root=newRoot;
        return newRoot;
    }
    Node *RRRoation(Node *node){
            return node;

    }
    Node *RLRoation(Node *node){
            return node;

    }
};
class Prec{
    int d;
    public:
    Prec(int k){d=k;}
    int chk(int key){
        if(!d){ return d=key;} return key;
    }
    void dis(){cout<<"Val is "<<d<<endl;}
};           
int main(){
    AVL t;
    int arr[]={50,10,20};
    for(int i=0;i<3;i++) t.insert(arr[i]);

    t.inorder();
    t.preorder();
    return 0;
}