#include<iostream>
using namespace std;
void byTail(int *arr,int len){    cout<<endl;
    int lastDup,count=0;
    for(int i=0;i<len-1;i++){
        if(arr[i]==arr[i+1] && lastDup!=arr[i]){
            lastDup=arr[i];
            count++;
            cout<<arr[i]<<", ";
        }
    }    cout<<endl;
    cout<<"Count = "<<count;
}
void byTailPlusCount(int *arr,int len){  
    for(int i=0;i<len-1;i++){
        if(arr[i]==arr[i+1]){
            int j=i+1;
            while(arr[j]==arr[i])j++;
            cout<<arr[i]<<" is appearing "<<j-i<<" times."<<endl;
            i=j-1;
        }
    } 

}
void hashing(int *arr,int len){
    cout<<"Last size = "<<arr[len-1]+1;
    int *H=new int[arr[len-1]];
    for(int i=0;i<len;i++)H[arr[i]]++;
    cout<<endl;
    for(int i=1;i<arr[len-1]+1;i++){
        if(H[i]>1)cout<<i<<" appearing "<<H[i]<<" times"<<endl;
    }
    cout<<endl;
}

void unsorted(int *arr,int len){
    for(int i=0;i<len;i++){
        int count=1;
        if(arr[i]!=-1){
            for(int j=i+1;j<len;j++){
                if(arr[i]==arr[j]){count++;arr[j]=-1;}
            }
            if(count>1)cout<<arr[i]<<" appearing "<<count<<" times."<<endl;
        }
    }
}
int main(){
    int arr[]={7,7,8,8,10,12,15,15,15,15};
    int unArr[]={8,3,6,4,6,5,6,8,2,5};
    // hashing(arr,10);
    unsorted(unArr,10);
    return 0;
}