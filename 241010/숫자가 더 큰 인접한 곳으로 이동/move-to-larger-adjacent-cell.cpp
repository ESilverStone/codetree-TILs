#include <iostream>
#include <vector>
using namespace std;

int n, r, c;
vector<vector<int>> arr;

int dirY[] = {-1,1,0,0};
int dirX[] = {0,0,-1,1};

void func(int y, int x) {
    cout << arr[y][x] << " ";

    int max = arr[y][x];
    int index = -1;

    for(int d=0; d<4; d++)
    {
        int newY = y + dirY[d];
        int newX = x + dirX[d];

        if(newX <= 0 || newY <= 0 || newX > n || newY > n) continue;

        int newNum = arr[newY][newX];

        if(max < newNum) 
        { 
            max = newNum;
            index = d;
            break;
        }

    }

    if(index != -1)
    {
        func(y+ dirY[index], x + dirX[index]);
    }


}

int main() {
    
    cin >> n >> r >> c;

    arr.resize(n+1, vector<int>(n+1));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i+1][j+1];
        }
    }


    func(r,c);


    return 0;
}