#include<iostream>
using namespace std;
// template <class T>
// class Heap{ 
//     int *arr;
//     int index;
//     public:
//     Heap(){arr=new int[100];index=1;} 
//     int insert(int data){   
        
//         return arr[index++]=data;  
//     }       
// };    


void insert(int *arr,int pos){
    int temp=arr[pos];

    // if maxHeap >
    for(;pos>1 && temp < arr[pos/2];pos/=2) arr[pos]=arr[pos/2];

    arr[pos]=temp; 
}

void deleteHeap(int *arr,int lastPos){
    int temp=arr[1];

    arr[1]=arr[lastPos];

    int i=1;
    int j=i*2;

    while(j < lastPos-1){
        // if maxHeap >
        if(arr[j+1] < arr[j]) j++;
        // if maxHeap >

        if(arr[j] < arr[i]) {
            arr[i]=arr[j]+arr[i];
            arr[j]=arr[i]-arr[j];
            arr[i]=arr[i]-arr[j];
            i=j;
            j=i*2;
        } else break; 
    }
    arr[lastPos]=temp;
}

int main(){
    // int arr[]={0,10,20,30,25,5,40,35};
    // // int arr[]={0,90,80,70,60,50,40,30};
    // cout<<endl<<"Before "<<"\t";
    // for(int i=1;i<8;i++) cout<<arr[i]<<", ";
    // for(int i=2;i<=7;i++) insert(arr,i);

    // cout<<endl<<"After "<<"\t";
    // for(int i=1;i<8;i++) cout<<arr[i]<<", ";
    
    // for(int i=7;i>1;i--) deleteHeap(arr,i);
    // // deleteHeap(arr,7);
    // cout<<endl<<"After Delete"<<"\t";
    // for(int i=1;i<8;i++) cout<<arr[i]<<", ";

    // cout<<endl;
    // char *name="AbdusSamad";
    // char *name='A';
    // char name='A';
    // char name[]="Abdus Samad";
    char name[]={'A','B'};

    for(int i=0;name[i];i++) cout<<name[i]<<" ,";
    cout<<endl<<"End = "<<name[2]<<" Name  = "<<sizeof name<<endl;
    return 0;
}