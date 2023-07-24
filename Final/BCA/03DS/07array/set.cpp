#include<iostream>
using namespace std;

class Set{
    int *arr;
    int length;
    int size;
    public:
    Set(int *arr,int length,int size){
        this->arr=arr;
        this->length=length;
        this->size=size;    
    }
    Set(){
        arr=NULL;
        length=0;
        size=0;
    }
    Set(int size){ 
        arr=new int[size];
        length=0;
        size=size;
    }
    Set * unionSet(Set temp){
        int i = 0, j = 0,k=0;
        Set * C = new Set(temp.length+length);

        while(i<length && j<temp.length){ 
            if(arr[i]<temp.arr[j]){
                C->arr[k++]=arr[i++];
            }
            else if(arr[i]>temp.arr[j]){
                C->arr[k++]=temp.arr[j++];
            }
            else {
                C->arr[k++]=arr[i++];
                j++;    
            }
        }
        while(i<length ) C->arr[k++]=arr[i++];
        while(j<temp.length) C->arr[k++]=temp.arr[j++]; 
        C->length=k; 
        return C;
    };
    Set * intersection(Set temp){
        int i=0,j=0,k=0;
        Set *C=new Set(temp.length+length);
        while(i<length&&j<temp.length){
            if(arr[i]==temp.arr[j]){ C->arr[k++]=arr[i++]; j++; }
            else if(arr[i]<temp.arr[j]) i++; else j++;
        }
        C->length=k;
        return C;
    }
    Set * diff(Set temp){
        int i=0,k=0,j=0;
        Set *C=new Set(length+temp.length);

        while (i<length && j<temp.length){
            if(arr[i]==temp.arr[j]) { i++; j++; }
            else if(arr[i]<temp.arr[j]) C->arr[k++]=arr[i++]; else j++;
        }

        while(i<length) C->arr[k++]=arr[i++]; 
        
        C->length=k;
        return C;       
    }
    void display(){
        
        cout<<endl<<"Set is :- [ ";
        for(int i=0;i<length;i++) cout<<arr[i]<<", ";
        cout<<" ]";
    }
};

int main(){
    int s1[10]={1,2,3,4,5,6,7,8,9,10};
    int s2[10]={11,12,13,14,15,16,17,18,19,20};
    Set A(s1,10,10);     
    A.display();  
    Set B(s2,10,10);
    B.display();  
    Set *C=A.unionSet(B);      
    C->display(); 
    Set *D=A.intersection(B);
    D->display(); 
    Set *E=A.diff(B);
    E->display(); 
 
    return 0;
}