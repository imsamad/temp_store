#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(){ next=NULL; data=0; }
        Node(int x){ data=x; next=NULL; }
};
    
class LL {
    Node * root;
    Node * last;
    int length;

    public:
    LL(){root=NULL;last=NULL;length=0;}
    LL(int*,int);
    ~LL();
    void create();
    void append(int);
    void display();
    void displayRec(Node*);
    void displayRecc(){
        displayRec(root);
    }
    int getLength();
    int getLengthRec(Node*);
    int getLengthRecc(){
        return getLengthRec(root);
    }
    int sum();
    int sumRec(Node*);
    int sumRecc(){
        return sumRec(root);
    }
    int max();
    int maxRec(Node*);
    int maxRecc(){
        return maxRec(root);
    }
    int search(int);
    int searchWithTranspose(int);
    int searchRec(Node *,int);
    int searchRecc(int k){
        return searchRec(root,k);
    }
    void insertSort(int);
    void insertSortTail(int);
    void metaData(){
        cout<<"Length "<<length<<endl;
        cout<<"Last one is"<<last->data;
    }
    int isSorted();
};

void LL::append(int a){
    Node *n =new Node(a);
    if(!root){ root=n; last=n; length++; }
    else{ last->next=n; last=n; length++; }
}

LL::~LL(){
        Node *temp=root;
        while(root){
        root=root->next;
        delete temp;
        temp=root;
}}

LL::LL(int *arr,int len){
        Node *n=new Node(arr[0]);
        root=n;
        last=n;
        length=1;
        int i=1;

        for(;i<len;i++){
            Node *n=new Node(arr[i]);
            last->next=n;    
            last=n;
            length++;
        }
}

void LL::create(){
    int c=0;    
    cout<<endl<<"Enter position \t";cin>>c;
    if(c<0) c=0; else c--;
    if(c > length) cout<<"Enter valid position";
    else{ 
    Node *n=new Node;
    if(c==0) { 
        cout<<"Enter No.";cin>>n->data;
        n->next=root;
        root=n;
        length++;
    }
    // else if(c == length || c==-1){
    //     cout<<"Enter Data.\t";cin>>n->data;
    //     last->next=n;
    //     last=n;
    //     length++;
    // }
    else{
        Node *temp=root;
        for(int i=0 ; i < c-1 ; i++) temp=temp->next;
        cout<<"Enter Data\t";cin>>n->data;
        n->next=temp->next;
        temp->next=n;
        length++;
    }}
}

void LL::display(){ 
    // cout<<endl<<"Length of List is "<<length<<endl;
    cout<<endl;
    Node *temp=root;
    if(length)
        while(temp){
            cout<<temp->data;
            if(temp->next) cout<<" => ";
            temp=temp->next;
        }
    else cout<<"Linked List is empty";
}

void LL::displayRec(Node *temp){
    if(temp->next) displayRec(temp->next);
    cout<<temp->data<<" => ";
}

int LL::getLength(){
    Node *temp=root;
    int len=0;
    while(temp) {temp=temp->next;len++;}
    return len;
}

int LL::sum(){
    int res=0;
    Node *temp=root;
    while(temp){
        res+=temp->data;
        temp=temp->next;
    }
    return res;
}

int LL::max(){
    Node *temp=root;
    int res=temp->data;
    while(temp){
        if(res < temp->data)res=temp->data;
        temp=temp->next;
    }
    return res;
}

int LL::search(int key){

    Node *temp=root,*tail=NULL;
    while(temp){
        if(key  == temp->data){
            tail->next = temp->next;
            temp->next = root;
            root  = temp;  
            // root->data=temp->data+root->data;
            // temp->data=root->data-temp->data;
            // root->data=root->data-temp->data;
        return 1;
        }
        tail=temp;
        temp=temp->next;
    }
    return 0;
}

int LL::searchWithTranspose(int key){
    Node *temp=root;
    if(temp->data==key) return key;
    while(temp){
        // cout<<"Xyz"<<temp->data<<endl;
        // cout<<"Cout "<<temp->next->data<<endl;
        if(temp->next && temp->next->data==key){
            temp->data = temp->data + temp->next->data;
            temp->next->data = temp->data - temp->next->data;
            temp->data = temp->data - temp->next->data;
            return key;
        }
        temp=temp->next;
    }
    return 0;    
}

int LL::getLengthRec(Node * temp){
    if(temp) return 1 + getLengthRec(temp->next);
    return 0;
    // return getLengthRec(temp->next) + 1;
}

int LL::sumRec(Node * temp){
    if(!temp) return 0;
    return temp->data + sumRec(temp->next);
    // return sumRec(temp->next) + temp->data;
}

int LL::maxRec(Node * temp){
    if(temp){
        // int x=0;
        // x=maxRec(temp->next);
        // cout<<"temp->data \t"<<temp->data<<"\t";
        // cout<<"x \t"<<x<<endl;
        // if(x > temp->data)
        // return x;
        // return temp->data;
        return maxRec(temp->next) > temp->data ? maxRec(temp->next) : temp->data;
    }
    return -11111;
}

int LL::searchRec(Node * temp,int k){
    return temp ? temp->data==k ? temp->data:searchRec(temp->next,k) : -1;
}

void LL::insertSort(int x){
    Node *temp=root;
    if(!length){ cout<<"List is empty"<<endl; return; }
    while(temp && temp->next && x>temp->next->data)
         temp=temp->next;   
    Node *n=new Node(x);
    if(!temp->next) last=n;
    n->next=temp->next;
    temp->next=n;
    length++;
}
void LL::insertSortTail(int x){
    Node *temp=root,*tail=NULL;
    if(!length){ cout<<"List is empty"<<endl; return; }
    while(temp && x > temp->data){
        tail=temp;
        temp=temp->next;   
    }
    Node *n=new Node(x);
    if(temp==root ){
        n->next=root;
        root=n;
    }else {
        if(!tail->next) last=n;
        n->next=tail->next;
        tail->next=n;
    }
    length++;
}

int LL::isSorted(){
    Node *temp=root;
    int x=temp->data;
    return 0;
}

int main(){
    int arr[5]={10,20,30,40,500};
    LL l(arr,5);
    // LL l;
    Node *n=new Node(5);


    // for(int i=0;i<5;i++) l.append(arr[i]);        
    // for(int i=0;i<5;i++){ l.display(); l.create(); 
// }        
    l.insertSortTail(25);
    l.display();
    l.insertSortTail(5);
    l.display();
    l.metaData();
    
    // l.displayRecc();
    // cout<<"Length is = "<<l.getLength()<<endl;
    // cout<<"RecLength is = "<<l.getLengthRecc()<<endl;
    // cout<<"Sum is = "<<l.sum()<<endl;
    // cout<<"Res Sum is = "<<l.sumRecc()<<endl;
    // cout<<"Max is = "<<l.max()<<endl;
    // cout<<"MaxRec is = "<<l.maxRecc()<<endl;searchWithTranspose
    // l.display();
    // cout<<endl<<"300 is = "<<l.search(10)<<endl;
    // cout<<endl<<"301 is = "<<l.search(301)<<endl;
    // cout<<"300 is = "<<l.searchWithTranspose(300)<<endl;
    // cout<<"301 is = "<<l.searchWithTranspose(301)<<endl;
    // l.display();

    // cout<<"300 is = "<<l.searchRecc(300)<<endl;
    // cout<<"301 is = "<<l.searchRecc(301)<<endl;
}