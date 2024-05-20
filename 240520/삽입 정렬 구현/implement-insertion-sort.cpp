#include <iostream>
#include <vector>

using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> arr;


    for(int i=0; i<n; i++){
        int ipt;
        cin >> ipt;

        arr.push_back(ipt);
    }

    int j = 0;
    for(int i=1; i<n; i++){
        j = i-1;
        int key = arr[i];
        while( j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;

        }

        arr[j+1] = key;
    }

   for(int i=0; i<n; i++){

        cout << arr[i] << " ";
    }


    return 0;
}