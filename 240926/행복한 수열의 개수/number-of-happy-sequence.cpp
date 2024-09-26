#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n));

    // 입력 받기
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    // 가로 검사
    for(int i=0; i<n; i++) {
        int cnt_row = 1;  // 연속된 원소 개수 카운트
        bool found_happy_row = false;  // 행복한 수열을 찾았는지 여부

        for(int j=1; j<n; j++) {
            if(arr[i][j] == arr[i][j-1]) {
                cnt_row++;
            } else {
                cnt_row = 1;  // 연속되지 않으면 다시 1로 초기화
            }

            // 연속된 원소가 m개 이상인 경우
            if(cnt_row >= m) {
                found_happy_row = true;
            }
        }

        // 해당 행이 행복한 수열이면 카운트
        if(found_happy_row) {
            ans++;
        }
    }

    // 세로 검사
    for(int i=0; i<n; i++) {
        int cnt_col = 1;  // 연속된 원소 개수 카운트
        bool found_happy_col = false;  // 행복한 수열을 찾았는지 여부

        for(int j=1; j<n; j++) {
            if(arr[j][i] == arr[j-1][i]) {
                cnt_col++;
            } else {
                cnt_col = 1;  // 연속되지 않으면 다시 1로 초기화
            }

            // 연속된 원소가 m개 이상인 경우
            if(cnt_col >= m) {
                found_happy_col = true;
            }
        }

        // 해당 열이 행복한 수열이면 카운트
        if(found_happy_col) {
            ans++;
        }
    }

    // 행복한 수열의 개수 출력
    cout << ans << endl;

    return 0;
}