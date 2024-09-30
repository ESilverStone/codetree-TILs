#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, q;
vector<vector<int>> arr;

// 두 행을 비교해서 같은 숫자가 있으면 true 반환
bool checkNumber(int line1, int line2) {
    for (int i = 0; i < m; i++) {
        if (arr[line1][i] == arr[line2][i]) {
            return true;
        }
    }
    return false;
}

// 한 행을 왼쪽 또는 오른쪽으로 밀기
void shiftRow(int row, bool dir) {
    if (!dir) {  // 오른쪽으로 밀기
        int temp = arr[row][m - 1];
        for (int i = m - 1; i > 0; i--) {
            arr[row][i] = arr[row][i - 1];
        }
        arr[row][0] = temp;
    } else {  // 왼쪽으로 밀기
        int temp = arr[row][0];
        for (int i = 0; i < m - 1; i++) {
            arr[row][i] = arr[row][i + 1];
        }
        arr[row][m - 1] = temp;
    }
}

// 특정 행에서 전파 시작
void changeLine(int line, bool dir, int sub) {
    int row = line;

    // 먼저 현재 행을 왼쪽 또는 오른쪽으로 밀기
    shiftRow(row, dir);

    // 위로 전파
    if (row > 0 && sub <= 0) {
        if (checkNumber(row, row - 1)) {
            changeLine(row - 1, !dir, -1);  // 방향을 반대로 해서 위로 전파
        }
    }

    // 아래로 전파
    if (row < n - 1 && sub >= 0) {
        if (checkNumber(row, row + 1)) {
            changeLine(row + 1, !dir, 1);  // 방향을 반대로 해서 아래로 전파
        }
    }
}

int main() {
    cin >> n >> m >> q;
    arr.resize(n, vector<int>(m));

    // 건물 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Q개의 바람 입력 처리
    for (int i = 0; i < q; i++) {
        int line;
        string dir;
        cin >> line >> dir;

        bool right = (dir == "R");  // 오른쪽으로 밀리는지 판단
        changeLine(line - 1, right, 0);
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}