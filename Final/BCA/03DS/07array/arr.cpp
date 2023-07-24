#include<iostream>
#include <cmath>
using namespace std;

void swap(int *a,int*b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

class Arr{
    int *A;
    int length;
    int size;
    public:
    Arr(){
        size=10;
        A= new int[size];
        length=0;
    }
    Arr(int *A,int s,int l=0){
        this->A=A;
        length=0;
        size=s;
        length=l;
    }
    void insert(int item,int pos){
        if(pos > length || pos>size || pos<0){
            cout<<"Invalid position";
        }
        else if(pos==length) A[length++]=item; 
        else { 
            for(int i=length;i>pos;i--) A[i]=A[i-1];
            A[pos]=item;
            length++;    
        }
    }
    void display(){ 
        cout<<endl<<"[ ";
        for(int i=0;i<length;i++) cout<<A[i]<<", ";
        cout<<"]";
    }
    int remove(int pos){
        if(pos>length || pos>size)return -1;
        else if(pos==length) return A[length--];
        else {
            for(int i=pos;i<length-1;i++) A[i]=A[i+1];
            return A[length--];
        } 
    }
    int biSearch(int key){
        int low=0,high=length-1,mid;
        while(low<=high){ 
            mid=floor((low+high)/2);
            if(A[low]==key) return low;
            else if(A[high]==key) return high;
            else if(A[mid]==key) return mid;
            else if(key<A[mid]) high=mid-1;
            else low=mid+1;
        }

    return -1;
    }

    int rBiSearch(int low,int high,int key){   
        if(low>high) return -1;

        int mid=floor((low+high)/2);
        if(A[low]==key) return low;
        else if(A[high]==key) return high;
        else if(A[mid]==key) return mid;
        else if(key<A[mid]) return rBiSearch(low,mid-1,key);
        else return rBiSearch(mid+1,high,key);
}

    int rrBiSearch(int key){
        return rBiSearch(0,length-1,key);
    }

    void reverse(){
        for(int i=0,j=length-1;i<j;i++,j--){
            A[i]=A[i]+A[j];
            A[j]=A[i]-A[j];
            A[i]=A[i]-A[j];
        }
    }
    void leftShift(){
        for(int i=0;i<length-1;i++) A[i]=A[i+1];
        length--;
    }
    void rotate(){
        int temp=A[0];
        for(int i=0;i<length-1;i++) A[i]=A[i+1];
        A[length-1]=temp;
    }
    void insertAtSort(int key){
        if(length==size) cout<<endl<<"Array overflow";
        else if(A[length-1] < key) A[length++]=key;
        else {
            int i=length-1;

            while(key < A[i]){ A[i+1]=A[i]; i--;
            } 
            cout<<endl<<" I = "<<i;
            display();
            A[i+1]=key;       
            length++;         
        }
    }
    int isSorted(){
        int flag=1;
        for(int i=0;i<length-1;i++) if(A[i] > A[i+1]) flag=-1;
        return flag;
    }
    void segragate(){
        int i=0,j=length-1;
        while(i<j){
            while(A[i]<0) i++;
            while(A[j]>=0) j--;
            if(i<j)swap(&A[i],&A[j]);    
        }
    }
};             
int main(){
    int arr[10]={-6,3,-8,10,5,-7,-9,12,-4,2};
    Arr a(arr,10,10);            
    // a.display(); 
    // a.segragate();
    // a.display(); 
    // cout<<endl<<a.rrBiSearch(8);
    // cout<<endl<<"11 "<<a.rrBiSearch(10);
    // cout<<endl<<"4 "<<a.rrBiSearch(4);
    // cout<<endl<<"6 "<<a.rrBiSearch(6);
    return 0;
}