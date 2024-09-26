#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int n, m;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    // 입력하기
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    m = 3;
    int count = 0;
    int max = 0;

    // 검사하기
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            count = 0;

            for(int k=0; k<m; k++)
            {
                for(int l=0; l<m; l++)
                {
                    if(i+k >= n || j+l >= n) break;

                    if(arr[i+k][j+l] == 1)
                    {
                        count++;
                    }
                }
            }

            if(count > max) {
                max = count;
            }
        }
    }

    cout << max;

    return 0;
}