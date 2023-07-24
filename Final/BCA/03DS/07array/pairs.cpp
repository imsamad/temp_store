#include<iostream>
using namespace std;
void find(int *arr,int len,int sum){
    for(int i=0;i<len-1;i++){
        int key=sum-arr[i];
        for(int j=i+1;j<len;j++)if(key==arr[j]){
            cout<<arr[i]<<" & "<<arr[j]<<" gives "<<sum<<endl;
        }
    }
}

void hashing(int *arr,int len,int sum,int max){
    int *H=new int[max];
    for(int i=0;i<len;i++){
        int key=sum-arr[i];
        if(H[key]!=0)cout<<key<<", "<<arr[i]<<" gives "<<sum<<endl;
        H[arr[i]]++;
}
}             

void pairSorted(int *arr,int len,int K){
    int i=0,j=len-1;
    while(i<j){
        int crtSum=arr[i]+arr[j];
        if(crtSum==K){
            cout<<arr[i]<<", "<<arr[j]<<" gives "<<K<<endl;
            i++;j--;
        }
        else if(crtSum>K){
            j--;
        }
        else if(crtSum<K){
            i++;
        }
    }
}
int main(){
    int arr[]={6,3,8,10,16,7,5,2,9,14}; 
    // find(arr,10,9);
    // cout<<"================"<<endl;      
    // hashing(arr,10,9,16);     
    int sortArr[]={1,2,3,4,5,6,7,10,11,12};
    pairSorted(sortArr,10,11);
    return 0;
}