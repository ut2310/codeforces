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
#define MAXN 2005

int N, C;
int arr[MAXN * 2][MAXN * 2];
int visited[MAXN * 2][MAXN * 2];
int x[MAXN];
int y[MAXN];
void ff(int var, int a, int b, int& size)
{
    //cout << a << " " << b << " " << size << "\n";
    if(a > 0 && b > 0 && a < N * 2 && b < N * 2)
    {
        if(visited[a][b] == 0)
        {
            visited[a][b] = var;
            if(arr[a][b] == 2)
            {
                size++;
            }
            ff(var, a - 1, b, size);
            ff(var, a + 1, b, size);
            ff(var, a, b - 1, size);
            ff(var, a, b + 1, size);
        }
    }
}
int compress(int a[MAXN], int size)
{
    int tmp[MAXN];
    for(int i = 0; i < size; i++)
    {
        tmp[i] = a[i];
    }
    sort(tmp, tmp + size);
    int nsize = unique(tmp, tmp + size) - tmp;
    for(int i = 0; i < size; i++)
    {
        int p = lower_bound(tmp, tmp + nsize, a[i]) - tmp;    
        a[i] = 2 * p;
        //cout << a[i] << " ";
    }
    //cout << "\n";
    return 2 * nsize;
} 
int main()
{
    freopen("crazy.in", "r", stdin);
	freopen("crazy.out", "w", stdout);
    cin >> N >> C;
    int cnt = 0;
    x[cnt] = -1;
    y[cnt] = -1;
    cnt++;
    x[cnt] = 1000005;
    y[cnt] = 1000005;
    cnt++;
    for(int i = 0; i < 2 * N + C; i++)
    {
        cin >> x[cnt] >> y[cnt];
        cnt++; 
    }
    compress(x, cnt);
    compress(y, cnt);
    
    for(int i = 0; i < N; i++)
    {
        int fi = i * 2 + 2;
        int si = i * 2 + 3;
        int x1 = x[fi], y1 = y[fi], x2 = x[si], y2 = y[si];
        if(x1 == x2)
        {
            for(int j = min(y1, y2); j <= max(y1, y2); j++)
            {
                arr[x1][j] = 1;
            }
        }
        if(y1 == y2)
        {
            for(int j = min(x1, x2); j <= max(x1, x2); j++)
            {
                arr[j][y1] = 1; //obstacle
            }
        }
    }
    for(int i = 0; i < C; i++)
    {
        int index = 2 + 2 * N + i;
        arr[x[index]][y[index]] = 2;
    }
    /*
    for(int i = 0; i < 20; i++)
    {
        cout << "\n";
        for(int j = 0; j < 20; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    */
    int largest = 0;
    int cnt2 = 1;
    for(int i = 0; i < MAXN * 2; i++)
    {
        for(int j = 0; j < MAXN * 2; j++)
        {
            if(visited[i][j] == 0 && arr[i][j] == 2)
            {
                int community = 0;
                ff(cnt2, i, j, community);
                cnt2++;
                if(community > largest)
                {
                    largest = community;
                }
            }
        }
    }
    cout << largest;
}
//Start: 1:00 End: 1:35
