#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<int> merged_arr;


void merged_sort(int low, int mid, int high){
  int i = low;
  int j = mid + 1;
  int k = low;

  while(i<=mid && j<=high) { 
    if(arr[i] <= arr[j]){
      merged_arr[k] = arr[i];
      k++;
      i++; 
    } else {
      merged_arr[k] = arr[j];
      k++;
      j++; 
    }
  }

  while (i <= mid){             // 아직 첫 번째 리스트 내 원소가 남아있다면
    merged_arr[k] = arr[i];      // 남은 원소들을 전부 옮겨줍니다.
    k += 1; i += 1;
  }
  while (j <= high){             // 아직 두 번째 리스트 내 원소가 남아있다면
    merged_arr[k] = arr[j];      // 남은 원소들을 전부 옮겨줍니다.
    k += 1; j += 1;
  }

  for(int k=low; k<=high; k++){
    arr[k] = merged_arr[k];
  }
}

void merge(int low,int high){
  if(low < high){
    int mid = (low + high) / 2;
    merge(low, mid);
    merge(mid + 1, high);
    merged_sort(low, mid, high);
  }
}


int main() {
    
    cin >> N;

    arr.resize(N); // 벡터의 크기를 설정합니다.
    merged_arr.resize(N); // 벡터의 크기를 설정합니다.

    for(int i=0; i<N; i++){
      cin >> arr[i];
    }

    merge(0, N-1);

    for(int i=0; i<N; i++){
      cout << arr[i] << " ";
    }
 
    return 0;
}