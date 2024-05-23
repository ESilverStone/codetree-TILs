#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

void swap(int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void heapify(int n, int i) {
    // i 인덱스에서 좌우 노드 검사
    int largest = i;
    int l = i * 2;
    int r = i * 2 + 1;

    if(l <= n && arr[largest] < arr[l]) {
        largest = l;
    }

    if(r <= n && arr[largest] < arr[r]) {
        largest = r;
    }

    if(largest != i){
        swap(largest, i);   
        heapify(n, largest);
    }
}

// 1. max heap으로 만든다.
// 2. 정렬 
void heap_sort(int n) {

    for(int i = n/2; i>=1; i--){
        heapify(n, i);
    }

    for(int i = n; i>1; i--){
        swap(i, 1);
        heapify(i-1, 1);
    }

}

int main() {
    cin >> n;

    // 힙을 구현하기 위해 배열은 0 index 값을 비운다.
    arr.resize(n+1);
    for(int i=0; i<n; i++){
        cin >> arr[i+1];
    }

    heap_sort(n);

    for(int i=0; i<n; i++){
        cout << arr[i+1] << " ";
    }

    return 0;
}