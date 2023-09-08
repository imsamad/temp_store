#include<bits/stdc++.h>
using namespace std;
int main() { 
        // implemented using BTS
        // Modification now allowd, only insertion and deletion allowed.
        set<int> s;

        s.insert(10);
        s.insert(10);
        s.insert(11);
        
        set<int>::iterator it = s.begin();
        // set<int>::iterator itn=it++;
        it++;
        s.erase(it);
        for(int i:s) {
           cout << i << endl;
        }

        cout << " " << s.count(11) << endl;
        set<int>::iterator itx = s.find(10);
        for(auto ity = itx; ity!=s.end(); ity++) {
        cout << *ity<<endl;
        }
        cout << *itx<<endl;
        
        // LogN
        // insert, erase, find and count
        return 0;
}