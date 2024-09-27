#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> arr;

int GetNumOfGold(int row, int col, int k) {
    int num_of_gold = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(abs(row - i) + abs(col - j) <= k)
            {
                num_of_gold += arr[i][j];
            }
        }
    }
    return num_of_gold;
}

int GetArea(int k) {
    return k * k + (k+1) * (k+1);
}

int main() {

    cin >> n >> m;

    arr.resize(n, vector<int>(n));

    // 입력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max_gold = 0;

    // 검사
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // k에 따른 골드 탐색
            for(int k=0; k <= 2 * (n-1); k++) 
            {
                int num_of_gold = GetNumOfGold(i,j,k);

                if(num_of_gold * m >= GetArea(k)) {
                    max_gold = max(max_gold, num_of_gold);
                }
            }
        }
    }

    cout << max_gold;

    return 0;
}