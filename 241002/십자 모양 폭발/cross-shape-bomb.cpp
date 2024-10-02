#include <iostream>
#include <vector>
using namespace std;

// 중력이 작용한 후의 배열을 만들어 주는 함수
void apply_gravity(vector<vector<int>>& arr, int n) {
    for (int col = 0; col < n; ++col) {
        int empty_row = n - 1; // 아래에서부터 빈 곳을 채워나감
        for (int row = n - 1; row >= 0; --row) {
            if (arr[row][col] != 0) {
                arr[empty_row][col] = arr[row][col];
                if (empty_row != row) {
                    arr[row][col] = 0; // 원래 자리는 비우기
                }
                empty_row--;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    r--;
    c--;

    int l = arr[r][c] - 1;

    arr[r][c] = 0;

    // 상하로 터지는 영역
    for (int i = 1; i <= l; i++) {
        if (r - i >= 0) arr[r - i][c] = 0; // 위쪽
        if (r + i < n) arr[r + i][c] = 0;  // 아래쪽
    }

    // 좌우로 터지는 영역
    for (int i = 1; i <= l; i++) {
        if (c - i >= 0) arr[r][c - i] = 0; // 왼쪽
        if (c + i < n) arr[r][c + i] = 0;  // 오른쪽
    }

    // 중력 작용
    apply_gravity(arr, n);

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}