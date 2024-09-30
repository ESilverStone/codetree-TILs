#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int n, t;
    cin >> n >> t;

    int m = 3;

    vector<vector<int>> arr(m, vector<int>(n));

    // 입력
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> temp(m);

    // temp 저장
    for(int i=0; i<m; i++)
    {
        temp[i] = arr[i][n-1];
    }

    // 로테이션
    for(int i=0; i<m; i++)
    {
        for(int j=n-1; j>0; j--)
        {
            arr[i][j] = arr[i][j-1];
        }

        if(i-1 < 0)
        {
            arr[i][0] = temp[m-1];
        }
        else 
        {
            arr[i][0] = temp[i-1];
        }
    }

    // 출력
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << "\n";
    }


    return 0;
}