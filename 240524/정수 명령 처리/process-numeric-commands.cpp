#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;

int main() {
    
    stack<int> s;

    cin >> n;

    for(int i=0; i<n; i++){
        string st;
        cin >> st;
        if(st == "push"){
            int ipt;
            cin >> ipt;
            s.push(ipt);
        } else if (st == "size") {
            cout << s.size() << "\n";
        } else if (st == "empty") {
            if(s.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (st == "pop") {
            if(!s.empty()) {cout << s.top() << "\n"; s.pop();}
        } else if (st == "top") {
            if(!s.empty()) cout << s.top() << "\n";
        }
    }

    return 0;
}