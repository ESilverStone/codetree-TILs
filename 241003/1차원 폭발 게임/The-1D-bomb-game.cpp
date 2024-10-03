#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool exploded = true;

    // 연속한 폭탄이 터지지 않을 때까지 반복
    while (exploded) {
        exploded = false;
        int cnt = 1;
        vector<int> newArr;

        // 폭탄이 터지는지 확인
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                cnt++;
            } else {
                // M개 이상 연속한 폭탄들이 있으면 폭발
                if (cnt >= m) {
                    exploded = true;
                } else {
                    // 연속하지 않은 폭탄들을 새로운 배열에 추가
                    for (int j = i - cnt; j < i; j++) {
                        newArr.push_back(arr[j]);
                    }
                }
                cnt = 1; // 카운트 초기화
            }
        }

        // 마지막에 남은 폭탄들도 처리
        if (cnt >= m) {
            exploded = true;
        } else {
            for (int j = n - cnt; j < n; j++) {
                newArr.push_back(arr[j]);
            }
        }

        // 새로운 배열로 갱신
        arr = newArr;
        n = arr.size();
    }

    // 최종 결과 출력
    if(arr[0] != 0)
    {
        cout << n << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}