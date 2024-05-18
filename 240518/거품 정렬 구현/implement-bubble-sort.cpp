#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;

    cin >> n;
    vector<int> arr;

    bool sorted = false;

    for(int i=0; i<n; i++){
        int input;
        cin >> input;

        arr.push_back(input);
    }

    while(sorted == false){
        sorted = true;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sorted = false;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}