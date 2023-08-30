/*
USER: ut23101
LANG: C++17
TASK: crazy
*/
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
#define MAXN 105
int arr[MAXN][MAXN];
int visited[MAXN][MAXN];
int res = 0;
void ff(int x, int y)
{
    if(x >= 0 && x < MAXN && y >= 0 && y < MAXN)
    {
        if(arr[x][y] == 1)
        {
            res++;
            return;
        }
        if(visited[x][y] == 0)
        {
            visited[x][y] = 1;
            ff(x - 1, y);
            ff(x + 1, y);
            ff(x, y - 1);
            ff(x, y + 1);
        }
    }
    return;
}
int main()
{
    freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
    }
    ff(0, 0);
    cout << res;
}
//Start: 1:15