#include <iostream>
#include <stack>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    stack<bool> st; 
    bool ans = true;

    for(char c : s){
        if(c == '('){
            st.push(true);
        } else {
            if(st.empty()) {
                ans = false;
                break;
            } else {
                st.pop();
            }
        }
    }

    if(!st.empty()) ans = false;

    if(ans) cout << "Yes";
    else cout << "No";

    return 0;
}