#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> arr;

    for(int i=0; i<n; i++){
        int ipt;
        cin >> ipt;

        arr.push_back(ipt);
    }

    // 전체 검사 후 가장 작은 값을 찾는다.
    for(int i=0; i<n; i++){
        int minIdx = 0;
        int min = arr[i];

        for(int j=i; j<n; j++){
            if(min > arr[j]){
                min = arr[j];
                minIdx = j;
            }
        }

        if(minIdx == 0) continue;

        // 교체
        int tmp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = tmp;
    }
    
    for(int i=0; i<n; i++){


        cout << arr[i] << " ";
    }

    return 0;
}