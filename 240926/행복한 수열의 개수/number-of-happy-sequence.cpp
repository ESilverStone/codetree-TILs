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

    for(int i=0; i<n; i++)
    {
        int maxCntRow = 1;

        for(int j=1; j<n; j++)
        {
            //if(maxCntRow >= m) break;

            if(arr[i][j] == arr[i][j-1])
            {
                maxCntRow++;
            }
            else
            {
                maxCntRow = 1;
            }

            if(maxCntRow >= m) break;
        }

        if(maxCntRow >= m) {
            ans++;
        }
    }

    for(int i=0; i<n; i++)
    {
        int maxCntCol = 1;

        for(int j=1; j<n; j++)
        {
            if(arr[j][i] == arr[j-1][i])
            {
                maxCntCol++;
            }
            else
            {
                maxCntCol = 1;
            }

            if(maxCntCol >= m) break;
        }
        if(maxCntCol >= m) {
            ans++;
        }
    }
    
    //ans = maxCntRow + maxCntCol;

    cout << (ans);

    return 0;
}