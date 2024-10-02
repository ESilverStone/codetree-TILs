#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;

int encoding() {

    int cnt = 1;
    int ans = 0;

    for(int i=1; i<str.length(); i++) 
    {
        if(str[i] == str[i-1]) {
            cnt++;
        }
        else {
            ans += 1;
            if(cnt >= 1) {
                ans += to_string(cnt).length();
            }
            cnt = 1;
        }
    }
    ans += 1;
    if (cnt >= 1) {
        ans += to_string(cnt).length();
    }
    return ans;
}


void shift() {
    int last = str.length() - 1;
    char temp = str.back();

    for(int i=last; i>0; i--)
    {
        str[i] = str[i-1];
    }

    str[0] = temp;
}

int main() {

    cin >> str;

    int minV = 1e9;

    for(int i=0; i<str.length(); i++) 
    {
        minV = min(minV, encoding());
        shift();
    }

    cout << minV;

    return 0;
}