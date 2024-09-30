#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, q;
vector<vector<int>> arr;

bool checkNumber(int line1, int line2) {
    bool check = false;

    for(int i=0; i<m; i++){
        if(arr[line1][i] == arr[line2][i]){
            check = true;
            break;
        }
    }

    return check;
}

void changeLine(int line, bool dir, int sub) {
    
    int row = line -1;
    // 오른쪽으로 로테이션
    if(!dir) {
        int temp = arr[row][m-1];

        for(int i=m-1; i>0; i--)
        {
            arr[row][i] = arr[row][i-1];
        }
        arr[row][0] = temp;

    }
    else {
        int temp = arr[row][0];

        for(int i=0; i<m-1; i++)
        {
            arr[row][i] = arr[row][i+1];
        }
        arr[row][m-1] = temp;
    }

    // 감소
    if(row > 0 && sub <= 0 ) {
        if(checkNumber(row, row - 1)) {
            changeLine(line - 1, !dir, -1);
        }
    }

    // 증가
    if(row < n - 1 && sub >= 0) {
        if(checkNumber(row, row + 1)) {
            changeLine(line + 1, !dir, 1);
        }
    }
}



int main() {
    
    int line = 0;
    bool right = true;
    string dir;
    
    // 입력
    cin >> n >> m >> q;

    arr.resize(n, vector<int>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 바람
    for(int i=0; i<q; i++)
    {
        cin >> line >> dir;
        if(dir == "L") { right = false; }

        changeLine(line, right, 0);
    }

    // 출력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }





    return 0;
}