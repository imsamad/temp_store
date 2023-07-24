#include<iostream>
#include <limits>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){this->data=data;right=left=NULL;}
};

class Stack{
    public:
    Node ** arr;
    int length;
    int size;
    Stack(){arr=new Node*[100];length=-1;size=100;}
    Node * pop(){return length > -1 ? arr [length--]:NULL;}
    Node * top(){
        return length > -1 ? arr[length]:NULL;
    }
    void push(Node *n){   if (length < size)arr[++length]=n;   }
};

class NodeSet{
    public:
    Node *tail,*index;
    NodeSet(Node *t,Node *p){        
        tail=t;index=p;
        // if(t==p)tail=NULL;
    }
};

class BST{
    Node *root;
    public:
    BST(){root=NULL;}
    BST(Node *root){this->root=root;}
    
    Node * search(Node *node,int key){
        if(!node) return NULL;
        if(node->data==key)return node;
        else if(node->data<key) return search(node->left,key);
        else search(node->right,key);
    }
    void rec_search(int key){Node *temp=search(root,key); cout<<"Node data is via rec :- "<<temp->data<<endl; }

    NodeSet * it_search(int key){
        Node *t=root,*tail=NULL; 
        while(t){
            // cout<<"OK";
            tail=t;
            if(t->left && t->left->data==key){
                // cout<<"equal left "<<t->left->data<<endl;
                NodeSet * set=new NodeSet(tail,t->left);
                return set;
            }
            else if(t->right && t->right->data==key){
                // cout<<"equal right "<<t->right->data<<endl;
                NodeSet * set=new NodeSet(tail,t->right);
                return set;
            }
            //  In case data found in first loop. e.g on root node.
            else if(t->data==key){
                // cout<<"equal right "<<t->right->data<<endl;
                NodeSet * set=new NodeSet(NULL,t);
                return set;
            }
            else if(key < t->data) {
                // cout<<"left "<<t->data<<endl;
                t=t->left;
            }
            else {
                // cout<<"right "<<t->data<<endl;
                t=t->right;
            }
        } 
        return NULL;
    }
    // void it_it_search(int key){Node *temp=it_search(key); cout<<"Node data is via it :- "<<temp->data<<endl; }

    NodeSet * InPred(Node *node){
        if(!node->left || !node) return NULL;

        Node *p=node->left,*tail=node;

        while(p->right){
            tail=p;
            p=p->right;
        }
        
        // return p;
        return new NodeSet(tail,p);
    }

    Node * InPred2(Node *node){
        while(node && node->right)
            node=node->right;
        return node;
    }

    Node * InSucc2(Node *node){
        while(node && node->left)
            node=node->left;
        return node;
    }

    NodeSet * InSucc(Node *node){
        if(!node->right || !node) return NULL;

        Node *p=node->right,*tail=node;

        while(p->left){
            tail=p;
            p=p->left;
        }
        
        // return p;
        return new NodeSet(tail,p);
    }

    void it_insert(int data){
        if(!root)
            root=new Node(data);

        Node *tail=NULL,*p=root;
        
        while(p){
            tail=p;
            if(p->data==data)return;
            else if(data < p->data) p=p->left;
            else p=p->right;
        }
        Node *temp=new Node(data);
        if(tail->data > data) tail->left=temp;
        else tail->right=temp;
    }
    
    Node * rec_insert(Node *node , int key){
        if(!node) return new Node(key); 

        else if(key< node->data)
            node->left=rec_insert(node->left,key);

        else if(key > node->data) 
            node->right=rec_insert(node->right,key);
        // If data is equal plus in all situation...
        return node;
    }
    void rec_rec_insert(int key){ 
        if(!root)  root=new Node(key);
        else rec_insert(root,key);
    }

    void preOrder(Node *node){
        if(node){        
            cout<<node->data<<"\t";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void rec_preOrder(){cout<<"PreOrder is ";preOrder(root);cout<<endl;}
    void inOrder(Node *node){
        if(node){       
            inOrder(node->left);
            cout<<node->data<<", ";
            inOrder(node->right);
        }
    }
    void rec_inOrder(){cout<<"inOrder is =>  ";inOrder(root);cout<<endl;}

       int isLeafNode(Node *node){
        return !node ? 0 : node->right==NULL && node->left==NULL ? 1 : 0;
    }

    // void deleteNode(int key){
    //     NodeSet *temp=it_search(key);
    //     if(temp){
    //         if(isLeafNode(temp->index)){
    //             if(temp->index == temp->tail->left){
    //                 temp->tail->left=NULL;
    //             }else temp->tail->right=NULL;
    //         }
    //     }
    // }
    int height(Node * node){
        if(!node) return 0;
        int left=height(node->left),right=height(node->right);
        // if(node->right && node->left) return left+right+1;
        // return left+right;
        return left > right ?  left+1 : right+1;
    }
    void deleteNode(int key){
        if(!root) return;
        NodeSet *keyNode=it_search(key);
        //  cout<<keyNode->tail->data<<" keyNode "<<keyNode->index->data<<endl;
        int keyNodeIsRoot=keyNode->index==root;
        //  int keyNodeIsRoot=keyNode->index==keyNode->tail;
         
        //  If node is leafNode
        // ----------------------
        if(isLeafNode(keyNode->index)){
             if(keyNodeIsRoot) root=NULL;
             else {
                if(key < keyNode->tail->data){
                    // cout<<"Left "<<keyNode->tail->data<<endl; 
                    keyNode->tail->left=NULL;
                }else{ 
                    //  cout<<"Right "<<keyNode->tail->data<<endl;
                    keyNode->tail->right=NULL;
                }
            }
        //  If node toBeDeleted is not a leafNode
        // -----------------------------------
         } else {
            NodeSet *preSet=InPred(keyNode->index);
            NodeSet *sucSet=InSucc(keyNode->index);
            //  cout<<preSet->tail->data<<" Predessor "<<preSet->index->data<<endl;
            //  cout<<sucSet->tail->data<<" Successor "<<sucSet->index->data<<endl;
            //  if predecessor is a leafNode
            if(preSet && isLeafNode(preSet->index)){
                // cout<<"One"<<endl;
                preSet->index->right=keyNode->index->right;
                //  Predeccsor is direct child of keyNode->index
                // in this case keyNode->index .i.e the node to be deleted would be co-incide with the pred tail...
                if(preSet->tail!=keyNode->index){ 
                    preSet->index->left=keyNode->index->left;                 
                    preSet->tail->right=NULL;
                }

                if(keyNodeIsRoot) root=preSet->index;
                else if(key < keyNode->tail->data) keyNode->tail->left=preSet->index;
                else keyNode->tail->right=preSet->index;        
                // cout<<"Finish "<<keyNode->tail->right->data<<endl;     
            //  if succcessor is a leafNode    
            } else if(sucSet && isLeafNode(sucSet->index)){ 
                // cout<<"Sec"<<endl;
                sucSet->index->left=keyNode->index->left;

                // Succcessor is direct child of keyNode->index
                // in this case keyNode->index .i.e the node to be deleted would be co-incide with the succ tail...
                if(sucSet->tail != keyNode->index) {
                    // cout<<"Hello "<<endl;
                    sucSet->index->right=keyNode->index->right;
                    sucSet->tail->left=NULL;

                }

                // Connect ancestors of keyNode->index to its new keyNode->index ...
                if(keyNodeIsRoot)root=sucSet->index;
                else if(key < keyNode->tail->data) keyNode->tail->left=sucSet->index;
                else keyNode->tail->right=sucSet->index;
            }
            // if pred & succ are not leafNode then replace keyNode->index w/  either pred or succ whose height is less.
            
            else if(height(keyNode->index->left)>0 && height(keyNode->index->left) < height(keyNode->index->right)){
                // replace with predcessor...
                if(keyNodeIsRoot){
                    preSet->index->right=root->right;
                    root=preSet->index;
                }
                else {
                    keyNode->tail->left=keyNode->index->left;
                }
                
            } else {
                cout<<"Two"<<sucSet->index->data<<endl;
                // replace with successor...
                if(keyNodeIsRoot){ 
                    sucSet->index->left=root->left;
                    root=sucSet->index;
                }
                else keyNode->tail->right=keyNode->index->right;
                // sucSet->index->left=keyNode->index->left;
                // Node *temp=sucSet->index->right;
                // sucSet->index->left=sucSet->index->right;
                // if(keyNodeIsRoot)root=sucSet->index;
                // else sucSet->index->right=keyNode->index->right;
                // sucSet->tail->left=temp;
            }
        }
    }

    Node * rec_delete(Node *p,int key){
        if(!p) return NULL;
        if(!p->left && !p->right && p->data==key){

            if(p==root)root=NULL;
            free(p);
            return NULL;
        }
        if(key<p->data)
            p->left=rec_delete(p->left,key);
        else if(key>p->data)
            p->right=rec_delete(p->right,key);
        else{
            Node *q;
            if( height(p->left) > height(p->right) ){
                // cout<<"Pre "<<endl;
                q=InPred2(p->left);
                p->data=q->data;
                p->left=rec_delete(p->left,q->data);
            } else {
                // cout<<"Succ"<<endl;
                q=InSucc2(p->right);
                p->data=q->data;
                p->right=rec_delete(p->right,q->data);    
            }
        }
        return p;
    }
    void rec_rec_delete(int key){
        Node *temp=rec_delete(root,key);
        // if(temp->data){
        //     // cout<<"Deleted Node is "<<temp->data<<endl;
        // }else {
        //     cout<<"Not resent"<<endl;
        // }
    }

    void fromPre(int *arr,int length){
        int i=0;
        root=new Node(arr[i++]);
        Node *p=root;
        Stack st;
        while(i<length){
            int thisVal=arr[i];
            // cout<<"Node data is "<<p->data<<" ,Val is "<<thisVal;
            if(thisVal < p->data ){
                // cout<<" ,One ";
                p->left=new Node(arr[i++]);;
                st.push(p);
                p=p->left;                
            }else  {
                // cout<<" ,Two ";
                Node *top=st.top();
                int topData;

                if(top) topData=top->data; else topData=std::numeric_limits<int>::max();
                //    cout<<" Top data "<<topData; 
                if(thisVal < topData && thisVal > p->data ){
                    // cout<<" ,Two a ";
                    p->right=new Node(arr[i++]);
                    p=p->right;
                }else{
                    // cout<<" Two b ";
                    p=st.pop();
                }
            }
                // cout<<endl;    
        }

    }
};             

int main(){
    BST t;
    // 
    // int arr[]={13,3,14,1,4,18,2,12,19,10,5,11,8,7,9,6};
    int arr[]={30,20,10,15,25,40,50,45};
    for(int i=0;i<14;i++) t.rec_rec_insert(arr[i]); 
    t.fromPre(arr,8);
    t.rec_preOrder();
    t.rec_inOrder();
    // t.rec_rec_delete(2);
    // t.rec_inOrder();  
    // NodeSet *keyNode=t.it_search(6);
    // cout<<keyNode->tail->data<<endl;
    // cout<<keyNode->index->data<<endl;
    return 0;
}