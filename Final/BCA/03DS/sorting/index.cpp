#include<iostream>
using namespace std;

void swap(int *a,int *b){
    cout<<"a= "<<*a<<", b= "<<*b<<endl;
    if(*a==*b) return;
    *a=*a+*b;
    *a=*a-*b;
    *b=*a-*b;
}
/*
void bubble(int *A,int length){
    for(int i=0;i<length-1;i++){
        int flag=0;
        for(int j=0;j<length-i-1;j++)
            if(A[j] > A[j+1]){
                swap(A[j],A[j+1]);
                flag++;
            }
        if(!flag) break;
    }        
}

void insert(int *A,int len){
    for(int i=1;i<len;i++){
        int temp=A[i],j=i-1;

        for(;j>-1 && A[j] >temp;j--) A[j+1]=A[j];

        A[j+1]=temp;
    }
}

void selection(int *A,int len){
    for(int i=0;i<len-1;i++){
        int k=i;

        for(int j=i+1;j<len;j++) k= A[j] < A[k]? j : k;
        // if(i==k) break;
        // cout<<"Exe"<<endl;
        swap(A[i],A[k]);
    }
}

int partition(int *A,int l,int h){
    int pivot=A[1];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j) swap(A+i,A+j);
    }while(i<j);

    swap(A+l,A+j);
    return j;
}

void Quick(int *A,int l,int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        Quick(A,l,j);
        Quick(A,j+1,h);
    }
}

void Merge(int *A,int l,int mid,int h,int chk=0){
    int i=l,j=mid+1,k=l;
    int B[h+1];
    while(i<=mid && j<=h){
         if(A[i] < A[j])
            B[k++]=A[i++];

        else if(A[i] > A[j])
            B[k++]=A[j++];
  
        else { B[k++]=A[i++]; j++; }
    }
    while(i<=mid) B[k++]=A[i++];
    while(j<=h) B[k++]=A[j++];

    if(chk){
    cout<<"Ok "<<chk<<"\t";
    for(i=l;i<=h;i++) cout<<B[i]<<" ,";
    cout<<endl;    
    }
    for(i=l;i<=h;i++) A[i]=B[i];
}

void IMerge(int *A,int len){ 
    int p=2;
    for(;p<=len;p=p*2){
        for(int i=0;i+p-1<len;i=i+p){
            int l=i,
                h=i+p-1,
                mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<len){
        // cout<<"p/2="<<p/2-1<<",len="<<len-1<<endl;    
        Merge(A,0,p/2-1,len-1,1);   
    }
}
void RMerge(int *A,int l,int h){
    // if(l==h ) return;
    // if(!l<h ) return;
    if(l>=h ) return;

    int mid=(l+h)/2;
    RMerge(A,l,mid);
    RMerge(A,mid+1,h);
    Merge(A,l,mid,h);
}
*/
void ShellSort(int *A,int len){
    for(int gap=len/2;gap>=1;gap/=2){
        for(int j=0;j<len;j++){
        // cout<<"j= "<<j<<endl;
            if(j+gap<len  && A[j] > A[j+gap] ){
                // cout<<"Ok";
                swap(A[j],A[j+gap]);
                int k=j;
                while(k-gap>=0 && A[k] < A[k-gap]){ swap(A[k],A[k-gap]); k=-gap;}
            }
        }
    }
}

void ShellSort2(int A[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap]=A[j];
                // swap(A)
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}

int main(){
    int n=11;
    int A[11]={11,13,7,12,16,9,24,5,10,3,2};
    // int A[n]={8,3,7,4,9,2,6,5,1,10,11};
    // int n=2;
    // int A[n]={22,5};
    cout<<"Before "<<"\t";
    for(int i=0;i<n;i++) cout<<A[i]<<" ,";
    // selection(A,n);
    // bubble(A,n);
    // Quick(A,0,n-1);
    // RMerge(A,0,n);
    ShellSort(A,n);
    cout<<endl<<"After"<<"\t";
    for(int i=0;i<n;i++) cout<<A[i]<<" ,";



    cout<<endl;
    return 0;
}