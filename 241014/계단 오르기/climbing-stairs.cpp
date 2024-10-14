#include <iostream>
#include <vector>
using namespace std;

int MAX_NUM = 1001;
vector<int> memo;

int fibo(int n) {
    if(memo[n] != -1)
    {
        return memo[n];
    }

    if(n > 3)
    {
        memo[n] = (fibo(n-2) + fibo(n-3)) % 10007;
    }

    return memo[n];
}


int main() {
    int n;
    cin >> n;

    memo.resize(MAX_NUM, -1);

    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;

    fibo(n);

    if(memo[n] == -1 || 0)
    {
        cout << 0;
    } else {
        cout << memo[n] % 10007;
    }

    return 0;
}