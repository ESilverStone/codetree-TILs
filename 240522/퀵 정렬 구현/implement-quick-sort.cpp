#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

// 스왑
void swap(int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int quick_sort(int low, int high) {
    int pivot = arr[high];

    // 왼쪽 선택값
    int i = low - 1;

    // 오른쪽 선택 값
    // pivot을 기준으로 작으면 왼쪽으로 크면 오른쪽으로 구분해야함
    for(int j = low; j < high; j++){
        if(arr[j] < pivot) {
            i++;
            swap(i,j);
        }

    }

    // 구분이 끝나면 pivot은 자기 자리에 넣기 위해 마지막 스왑
    swap(i+1, high);

    return i+1;
}

void part (int low, int high) {
    if (low < high) {
        int pos = quick_sort(low, high); 
        part(low, pos - 1);  
        part(pos + 1, high);  
    } 
}


int main() {
    cin >> n;
    arr.resize(n); 

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    part(0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}