#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    // 가로 검사
    for(int i=0; i<n; i++)
    {
        int cnt_row = 1;
        int cnt_col = 1;
        bool s_row = false;
        bool s_col = false;

        for(int j=1; j<n; j++)
        {
            if(arr[i][j] == arr[i][j-1])
            {
                cnt_row++;
            } else {
                if(cnt_row >= m) {
                    ans++;
                    s_row = true;
                }
                cnt_row = 1;
            }

            if(arr[j][i] == arr[j-1][i])
            {
                cnt_col++;
            } else {
                if(cnt_row >= m) {
                    ans++;
                    s_col = true;
                }
                cnt_col = 1;
            }
        }

        if(!s_row && cnt_row >= m) ans++;
        if(!s_col && cnt_col >= m) ans++;


    }


    cout << (ans);

    return 0;
}