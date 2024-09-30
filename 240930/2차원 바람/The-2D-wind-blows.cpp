#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
vector<vector<int>> arr;
vector<vector<int>> sub;
int r1, c1, r2, c2;

int dirY[] = {1,0,-1,0};
int dirX[] = {0,1,0,-1};


void copy() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            sub[i+1][j+1] = arr[i+1][j+1];
        }
    }
}

void avg() {
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            
            int sum = sub[i][j];
            int cnt = 1;

            for(int k=0; k<4; k++)
            {
                int newY = dirY[k] + i;
                int newX = dirX[k] + j;

                if(newX == 0 || newY == 0 || newX > m || newY > n) continue;

                sum += sub[newY][newX];

                cnt++;    
            }

            sum /= cnt;

            arr[i][j] = sum;
        }
    }
}


void rotation() {
    // r1, c1으로 부터 아래에 있는거 위로
    int temp1 = arr[r1][c1];

    // 아래에 있는 원소 넣기
    for(int i=r1; i<r2; i++)
    {
        arr[i][c1] = arr[i+1][c1];
    }

    // 오른쪽에 있는 원소 넣기
    for(int i=c1; i<c2; i++)
    {
        arr[r2][i] = arr[r2][i+1];
    }

    // 위에 있는 원소 넣기
    for(int i=r2; i>r1; i--)
    {
        arr[i][c2] = arr[i-1][c2];
    }

    // 왼쪽에 있는 원소 넣기
    for(int i=c2; i>c1; i--)
    {
        arr[r1][i] = arr[r1][i-1];
    }

    arr[r1][c1+1] = temp1;

    copy();
    avg();
}





int main() {
    cin >> n >> m >> q;

    arr.resize(n+1, vector<int>(m+1));
    sub.resize(n+1, vector<int>(m+1));

    // 입력
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i+1][j+1];
        }
    }

    // q 회수만큼 회전
    for(int i=0; i<q; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;

        rotation();
    }

    // 출력
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i+1][j+1] << " ";
        }
        cout << "\n";
    }

    return 0;
}