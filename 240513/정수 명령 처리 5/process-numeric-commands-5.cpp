#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  // 여기에 코드를 작성해주세요.
  int n;
  cin >> n;

  vector<int> vec;

  for(int i=0; i<n; i++) {

    string s;
    cin >> s;

    if (s == "push_back") {
        int m;
        cin >> m;
        vec.push_back(m);
    } else if (s == "get") {
        int m;
        cin >> m;
        cout << vec[m-1] << "\n";
    } else if (s == "size") {
        cout << vec.size() << "\n";
    } else if (s == "pop_back") {
        vec.pop_back();
    }
  }

  return 0;
}