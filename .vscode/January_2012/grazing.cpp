using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
int visited[5][5];
int K;
int count_paths(int x, int y)
{
    if(x >= 5 || x < 0  || y >= 5 || y < 0 || visited[x][y] == 1)
    {
        return 0;
    }
    if(K == 24 && x == 4 && y == 4)
    {
        return 1;
    }
    K++;
    visited[x][y] = 1;
    int rv = count_paths(x - 1, y) + count_paths(x + 1, y) + count_paths(x, y - 1) + count_paths(x, y + 1);
    visited[x][y] = 0;
    K--;
    return rv;
}
int main()
{
    int a, b;
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> a >> b;
        visited[a - 1][b - 1] = 1;
    }
    cout << count_paths(0, 0);
}