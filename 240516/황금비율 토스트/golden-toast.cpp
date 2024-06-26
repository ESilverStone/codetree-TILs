#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    
    list<char> l;
    for(int i=0; i<s.length(); i++)
        l.push_back(s[i]);

    // iterator
    list<char>::iterator it = l.end();

    while(m--)
    {
        char cmd;
        cin >> cmd;

        if(cmd == 'L') {
            if(it != l.begin())   
                it--;             
        } 
        else if(cmd == 'R') {
            if(it != l.end())     
                it++;           
        }
        else if(cmd == 'D') {
            if(it != l.end())
                it = l.erase(it); 
        }
        else if(cmd == 'P') {
            char c;
            cin >> c;
            l.insert(it, c);      
        }   
    }
    for(list<char>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }
    return 0;
}