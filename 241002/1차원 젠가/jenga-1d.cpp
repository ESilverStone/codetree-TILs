#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;  

    vector<int> blocks(n); 
    for (int i = 0; i < n; ++i) {
        cin >> blocks[i];  
    }

    int s1, e1, s2, e2;
    cin >> s1 >> e1;  
    cin >> s2 >> e2;  

    s1--; e1--;
    s2--; e2--;

    // 첫 번째 구간 제거
    vector<int> remaining_blocks;
    for (int i = 0; i < n; ++i) {
        if (i < s1 || i > e1) {  // 구간 밖에 있는 블록만 남김
            remaining_blocks.push_back(blocks[i]);
        }
    }

    // 두 번째 구간 제거 (첫 번째 제거 후 남은 블록에 대해서)
    vector<int> final_blocks;
    for (int i = 0; i < remaining_blocks.size(); ++i) {
        if (i < s2 || i > e2) {  // 구간 밖에 있는 블록만 남김
            final_blocks.push_back(remaining_blocks[i]);
        }
    }

    // 결과 출력
    cout << final_blocks.size() << endl;  // 남은 블록 개수
    for (int i = 0; i < final_blocks.size(); ++i) {
        cout << final_blocks[i] << endl;  // 남은 블록들 출력
    }

    return 0;
}