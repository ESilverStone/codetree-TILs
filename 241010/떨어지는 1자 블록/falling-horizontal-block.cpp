#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m ,k;
vector<vector<int>> arr;

int func(int y, int x) {

    int num = n;

    for(int i=1; i<=n; i++)
    {
        if(arr[i][x] == 1)
        {
            num = i - 1;
            break;
        }
    }


    return num;

}

int main() {
    
    cin >> n >> m >> k;
    arr.resize(n+1, vector<int>(n+1));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i+1][j+1];
        }
    }

    int minV = 101;
    for(int i=0; i<m; i++) {
        minV = min(minV, func(1, k+i));       
    }

    for(int i=0; i<m; i++) {
        arr[minV][k+i] = 1;        
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i+1][j+1] << " ";
        }
        cout << "\n";
    }


    return 0;
}