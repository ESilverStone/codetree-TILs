#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n = 4;

void move(vector<vector<int>>& arr, int dir) {
    vector<vector<int>> new_arr(4, vector<int>(4, 0)); // 결과를 저장할 배열
    stack<int> st;

    switch(dir)
    {
        // 오른쪽으로
        case 1:
            for (int i = 0; i < n; i++) {
                for (int j = n - 1; j >= 0; j--) {  // 오른쪽부터 탐색
                    if (arr[i][j] != 0) {
                        if (!st.empty() && st.top() == arr[i][j]) {
                            // 스택의 탑이 현재 숫자와 같으면 합침
                            int merged = st.top() * 2;
                            st.pop();
                            st.push(merged + 1);
                        } else {
                            // 스택이 비어있거나 다른 숫자면 스택에 추가
                            st.push(arr[i][j]);
                        }
                    }
                }
                // 스택에서 값을 꺼내서 새 배열에 채우기 (오른쪽부터)
                int idx = n - 1;
                while (!st.empty()) {
                    int top = st.top();
                    new_arr[i][n - st.size()] = top % 2 == 1 ? top - 1 : top;
                    st.pop();
                }
            }
            break;

        // 왼쪽으로
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {  // 왼쪽부터 탐색
                    if (arr[i][j] != 0) {
                        if (!st.empty() && st.top() == arr[i][j]) {
                            int merged = st.top() * 2;
                            st.pop();
                            st.push(merged + 1);
                        } else {
                            st.push(arr[i][j]);
                        }
                    }
                }
                // 스택에서 값을 꺼내서 새 배열에 채우기 (왼쪽부터)
                int idx = 0;
                while (!st.empty()) {
                    int top = st.top();
                    new_arr[i][st.size()-1] = top % 2 == 1 ? top - 1 : top;
                    st.pop();
                }
            }
            break;

        // 위쪽으로
        case 3:
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {  // 위쪽부터 탐색
                    if (arr[i][j] != 0) {
                        if (!st.empty() && st.top() == arr[i][j]) {
                            int merged = st.top() * 2;
                            st.pop();
                            st.push(merged + 1);
                        } else {
                            st.push(arr[i][j]);
                        }
                    }
                }
                // 스택에서 값을 꺼내서 새 배열에 채우기 (위쪽부터)
                int idx = 0;
                while (!st.empty()) {
                    int top = st.top();
                    new_arr[st.size()-1][j] = top % 2 == 1 ? top - 1 : top;
                    st.pop();
                }
            }
            break;

        // 아래쪽으로
        case 4:
            for (int j = 0; j < n; j++) {
                for (int i = n - 1; i >= 0; i--) {  // 아래쪽부터 탐색
                    if (arr[i][j] != 0) {
                        if (!st.empty() && st.top() == arr[i][j]) {
                            int merged = st.top() * 2;
                            st.pop();
                            st.push(merged + 1);
                        } else {
                            st.push(arr[i][j]);
                        }
                    }
                }
                // 스택에서 값을 꺼내서 새 배열에 채우기 (아래쪽부터)
                int idx = n - 1;
                while (!st.empty()) {
                    int top = st.top();
                    new_arr[n-st.size()][j] = top % 2 == 1 ? top - 1 : top;
                    st.pop();
                }
            }
            break;
    }

    arr = new_arr; // 결과 배열을 원래 배열로 업데이트
}

int main() {
    vector<vector<int>> arr(4, vector<int>(n));

    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    char c;
    cin >> c;

    switch(c)
    {
        case 'R':
            move(arr, 1);
            break;
        case 'L':
            move(arr, 2);
            break;
        case 'U':
            move(arr, 3);
            break;
        case 'D':
            move(arr, 4);
            break;
    }

    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}