#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    // 입력하기
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> dicX = {1,0,-1,0};
    vector<int> dicY = {0,-1,0,1};

    int max = 0;

    // 검사하기
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            vector<int> nums;

            for(int k=0; k<4; k++)
            {
                int newX = i+dicX[k];
                int newY = j+dicY[k];

                if(newX < 0 || newY < 0 || newX >= n || newY >= m) continue;

                nums.push_back(arr[newX][newY]);
            }

            sort(nums.begin(), nums.end(), greater<int>());


            int sum = arr[i][j] + nums[0] + nums[1];

            if(max < sum) max = sum;
        }

    }

    cout << max;

    return 0;
}