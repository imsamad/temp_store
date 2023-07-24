#include<iostream>
using namespace std;
void bySum(int *arr,int len){
    int sum=0,actualSum=(len*(len+1))/2;
    for(int i=0;i<len;i++)sum+=arr[i];
    if(sum!=actualSum){
        cout<<"Missed Element is :- "<<actualSum-sum;
    }
}


void miss(int * arr,int len){   
    int diff=arr[0]-0,crtIndexDiff;
    cout<<endl;
    for(int i=1;i<len;i++){
        crtIndexDiff=arr[i]-i;
        if(crtIndexDiff==diff-1){
            diff--;
        }
        else if(crtIndexDiff!=diff){
            while(diff<crtIndexDiff){  
                cout<<diff+i<<", ";
                diff++;
            }
        }
    }
    cout<<endl;
}
void hashMethod(int *arr,int len){
    int *H=new int[arr[len-1]+1];

    for(int i=0;i<len;i++)H[arr[i]]++;

    for(int i=1;i<arr[len-1]+1;i++) if(!H[i]) cout<<i<<", ";
}
int main(){

    int arr[]={6,7,8,9,11,12,15,16,18,19};
    int arr1[]={3,6,8,8,10,12,15,15,15,20};
    int arr2[]={0,1,2,3,4,5,7,8,9,10};
    miss(arr1,10);
    // bySum(arr2,10);
    // hashMethod(arr2,10);
    return 0;
}