#include<bits/stdc++.h>
using namespace std;
int main() {
   vector<int> v;
   v.push_back(10);
   v.push_back(7);
   v.push_back(4);
   v.push_back(45);
   v.push_back(56);
   v.push_back(987);
   v.push_back(6);
   for(int i:v) {
      cout << i << " ";
   } cout << endl;
   
   // Based on intro sort - 
   sort(v.begin(), v.end());

   cout << " " <<binary_search(v.begin(), v.end(),10);
   cout << endl;
   
   for(int i:v) {
      cout << i << " ";
   } cout << endl;
   
   cout << "Lower bound " << lower_bound(v.begin(), v.end(), 10) - v.begin() << endl;
   cout << "Upper bound " << upper_bound(v.begin(), v.end(), 10) - v.begin() << endl;
   int a = 10, b = 7;
   max(a,b);
   min(a,b);
   swap(a,b);
   reverse(v.begin(), v.end());
   string st  = "Abdus Samad";
   reverse(st.begin(), st.end());
   
   // Rotate the vector elements so that element at index 3 becomes the new first element
   rotate(v.begin(),v.begin() +1,v.end());
   for(int i:v) {
      cout << i << " ";
   } cout << endl;
   
   return 0;
}