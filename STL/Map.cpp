#include<bits/stdc++.h>
using namespace std;
int main() {
         // Store value in key-value pair;
         // All key must be unique.
         // implemented using red-black tree
         map<int, string> m;
         m.insert({1:"abdus"}); // LogN

         m.count(1);// LogN
         // Find return iterator of that particular element.
         map<int, string>::iterator it = m.find(1); // LogN

         m.erase(1);// LogN
 
         m.second;

        return 0;
}