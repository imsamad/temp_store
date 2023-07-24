#include<iostream>
using namespace std;

class LowerTri{
    int *arr,n;
    public:
    LowerTri(int size){
        n=size;
        arr=new int[(n*(n+1))/2];
    }
    void Set(int data,int i,int j){
        int pos=(i*(i-1)/2)+j-1;
        if(i>=j && i<=n && j<=n ) arr[pos]=data;
    }
    int Get(int i,int j){
        int pos=(i*(i-1)/2)+j-1;
        return i>=j && i<=n && j<=n ? arr[pos] : 0;
    }
    void Display(){
        cout<<"Matrix is :- "<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<Get(i,j)<<"="<<i<<"+"<<j<<"\t";
            cout<<endl;
        }    
    }
};

class UpperTri{ 
    int *arr,n;
    public:
    UpperTri(int size){n=size; arr= new int[n*(n+1)/2]; }
    void Set(int data,int i,int j){
        if(j<i) return; 
 
        int temp=n-i+1;
        int pos=(n*(n+1)/2)-(temp*(temp+1)/2)+j-i;
        arr[pos]=data; 
    }
    int Get(int i,int j){
        if(j<i) return 0; 

        int temp=n-i+1;
        int pos=(n*(n+1)/2)-(temp*(temp+1)/2)+j-i;
        
        return arr[pos]; 
    }
    void Display(){
        cout<<"Matrix is :- "<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<Get(i,j)<<"="<<i<<"+"<<j<<"\t";
            cout<<endl;
        }    
    }
};
class TiaDiag{
    int *arr,n;
    public:
    TiaDiag(int size){ 
        n=size;
        arr= new int[3*n-2];
    }
    void Set(int data,int i,int j){
        if(i-j==1) arr[i-2]=data;
        else if(i-j==0) arr[n-1+i-1]=data;   
        else if(i-j==-1) arr[2*n-1+i-1]=data;
    }
    int Get(int i,int j){
        return i-j==1 ?  arr[i-2] : i-j==0 ? arr[n-1+i-1] : i-j==-1 ? arr[2*n-1+i-1]:0;

    }
    void Display(){
        cout<<"Matrix is :- "<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<Get(i,j)<<"="<<i<<"+"<<j<<"\t";
            cout<<endl;
        }    
    }
    
};

class SquareBand{
    int *arr,n,noOfDiag;

};
class Toeplitz{
    int *arr,n;
    public:
    Toeplitz(int size){
        n=size;
        arr=new int[2*n-1];
    }
    void Set(int data,int i,int j){ 
        if(i==1) arr[j-1]=data; 
        else if(j==1 && i!=1 ) arr[n+i-2]=data;    
    }
    int Get(int i,int j){
        return i<=j ? arr[j-i] : arr[n+i-j-1];  
    }
    void Display(){
        cout<<"Matrix is :- "<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<Get(i,j)<<"\t";
            cout<<endl;
        }
    }
};
int main(){
    Toeplitz L(5);
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                L.Set(i+j,i,j);

    L.Display();


    return 0;
}