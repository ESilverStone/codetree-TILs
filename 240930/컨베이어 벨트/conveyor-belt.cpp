#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, t;

    cin >> n >> t;

    vector<int> arr1(n);
    vector<int> arr2(n);

    // 입력
    for(int i=0; i<n; i++)
    {
        cin >> arr1[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> arr2[i];
    }

    // 로테이션
    for(int i=0; i<t; i++)
    {
        int temp1 = arr1[n-1];
        int temp2 = arr2[n-1];

        for(int j=n; j>1; j--)
        {
            arr1[j-1] = arr1[j-2];
        }
        arr1[0] = temp2;

        for(int j=n; j>1; j--)
        {
            arr2[j-1] = arr2[j-2];
        }
        arr2[0] = temp1;
    }

    // 출력
    for(int i=0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\n";

    for(int i=0; i<n; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}