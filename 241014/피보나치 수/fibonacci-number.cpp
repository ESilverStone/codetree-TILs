#include <iostream>
#include <vector>
using namespace std;

int MAX_NUM = 46;
vector<int> memo;

int fibo(int n) {
    if(memo[n] != -1)
    {
        return memo[n];
    }

    if(n > 2)
    {
        memo[n] = fibo(n-1) + fibo(n-2);
    }

    return memo[n];
}


int main() {
    int n;
    cin >> n;

    memo.resize(MAX_NUM, -1);

    memo[1] = 1;
    memo[2] = 1;

    fibo(n);

    cout << memo[n];

    return 0;
}