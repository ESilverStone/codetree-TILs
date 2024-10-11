#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r, c;
vector<vector<int>> arr;

class Dice {
public:
    int top = 1, bottom = 6, left = 4, right = 3, front = 2, back = 5;

    void rollLeft() {
        int temp = top;
        top = right;
        right = bottom;
        bottom = left;
        left = temp;
    }

    void rollRight() {
        int temp = top;
        top = left;
        left = bottom;
        bottom = right;
        right = temp;
    }

    void rollUp() {
        int temp = top;
        top = front;
        front = bottom;
        bottom = back;
        back = temp;
    }

    void rollDown() {
        int temp = top;
        top = back;
        back = bottom;
        bottom = front;
        front = temp;
    }
};

int main() {
    cin >> n >> m >> r >> c;
    arr.resize(n + 1, vector<int>(n + 1));

    Dice dice;
    arr[r][c] = dice.bottom;

    for (int i = 0; i < m; i++) {
        char dir;
        cin >> dir;

        switch (dir) {
            case 'L':
                if (c - 1 <= 0) continue;
                c = c - 1;
                dice.rollLeft();
                arr[r][c] = dice.bottom;
                break;

            case 'R':
                if (c + 1 > n) continue;
                c = c + 1;
                dice.rollRight();
                arr[r][c] = dice.bottom;
                break;

            case 'U':
                if (r - 1 <= 0) continue;
                r = r - 1;
                dice.rollUp();
                arr[r][c] = dice.bottom;
                break;

            case 'D':
                if (r + 1 > n) continue;
                r = r + 1;
                dice.rollDown();
                arr[r][c] = dice.bottom;
                break;
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += arr[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}