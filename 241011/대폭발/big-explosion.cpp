#include <iostream>
#include <vector>
using namespace std;

int n, m, r, c;
vector<vector<int>> arr;
vector<vector<int>> temp;

int dirY[] = {-1,1,0,0};
int dirX[] = {0,0,-1,1};

void func(int time) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(arr[i][j] == 1)
            {
                for(int d=0; d<4; d++){
                    int newY = i + dirY[d] * time;
                    int newX = j + dirX[d] * time;

                    if(newX <= 0 || newY <= 0 || newX > n || newY > n) continue;

                    temp[newY][newX] = 1;

                    
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(temp[i][j] == 1) arr[i][j] = 1;
        }
    }
}

int main() {
    cin >> n >> m >> r >> c;
    arr.resize(n + 1, vector<int>(n + 1));
    temp.resize(n + 1, vector<int>(n + 1));

    // 시작 점 폭탄
    arr[r][c] = 1;

    // 시간만큼 반복
    for(int t=1; t<=m; t++)
    {  
        func(t);
    }
    

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(arr[i][j] == 1)
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}