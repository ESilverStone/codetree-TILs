#include <iostream>
#include <list>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    list<int> ls;

    while(n--){
        string s;
        cin >> s;

        if(s == "push_back"){
            int m;
            cin >> m;

            ls.push_back(m);
        } else if(s == "push_front") {
            int m;
            cin >> m;

            ls.push_front(m);
        } else if(s == "pop_front") {
            int m = ls.front();
            cout << m << "\n";
            ls.pop_front();
        } else if(s == "pop_back") {
            int m = ls.back();
            cout << m << "\n";
            ls.pop_back();
        } else if(s == "size") {
            cout << ls.size() << "\n";
        } else if(s == "empty") {
            if(ls.empty())
            {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if(s == "front") {
            int m = ls.front();
            cout << m << "\n";
        } else if(s == "back") {
            int m = ls.back();
            cout << m << "\n";
        }



    }



    return 0;
}