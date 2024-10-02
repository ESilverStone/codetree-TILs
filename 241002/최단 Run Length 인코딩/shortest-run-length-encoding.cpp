#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;

int encoding() {

    char temp = str[0];
    int cnt = 0;
    int ans = 0;

    for(int i=0; i<str.length(); i++) 
    {
        if(temp != str[i])
        {
            ans += cnt / 10 + 2; 
            cnt = 1;

        }
        else
        {
            cnt++;
        }

        temp = str[i];
    }

    return ans;
}


void shift() {
    int last = str.length() - 1;
    char temp = str[last];

    for(int i=last; i>0; i--)
    {
        str[i] = str[i-1];
    }

    str[0] = temp;
}

int main() {

    cin >> str;

    int maxV = 0;

    for(int i=0; i<str.length(); i++) 
    {
        shift();
        maxV = max(maxV, encoding());
    }

    cout << maxV;

    return 0;
}