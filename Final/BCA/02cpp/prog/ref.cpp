#include<iostream>
using namespace std;
int main(){

    int a=10;
    int &b=a;
    int *c=&a;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<*c;

    return 0;
}