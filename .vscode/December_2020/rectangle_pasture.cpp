/*
USER: ut23101
LANG: C++17
TASK: rectangle
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
#define MAXN 2505
int N, arrx[MAXN], arry[MAXN];
vector<pair<int, int>> input;
vector<pair<int, int>> compressed;
int ps[MAXN][MAXN];
int cowarr[MAXN][MAXN];
int searchx(int a)
{
    for(int i = 0; i < N; i++)
    {
        if(arrx[i] == a)
        {
            return i;
        }
    }
    return -1;
}
int searchy(int b)
{
    for(int i = 0; i < N; i++)
    {
        if(arry[i] == b)
        {
            return i;
        }
    }
    return -1;
}
long long int prefixsum(int x1, int y1, int x2, int y2)
{
    int a = ps[x2][y2];
    int b = (x1 == 0)?0: ps[x1 - 1][y2]; 
    int c = (y1 == 0)?0: ps[x2][y1 - 1];
    int d = (!x1 || !y1)?0: ps[x1 - 1][y1 - 1];
    return a - b - c + d;
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        arrx[i] = x;
        arry[i] = y;
        input.push_back(make_pair(x, y));
    }
    sort(arrx, arrx + N);
    sort(arry, arry + N);
    for(int i = 0; i < N; i++)
    {
        int a = searchx(input[i].first);
        int b = searchy(input[i].second);
        compressed.push_back(make_pair(a, b));
        cowarr[a][b] = 1;
    }
    ps[0][0] = cowarr[0][0];
    for(int i = 1; i < N; i++)
    {
        ps[0][i] = ps[0][i - 1] + cowarr[0][i];
    }
    for(int i = 1; i < N; i++)
    {
        ps[i][0] = ps[i - 1][0] + cowarr[i][0];
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < N; j++)
        {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + cowarr[i][j];
        }
    }
    /*
    for(int i = 0; i < N; i++)
    {
        cout << "\n";
        for(int j = 0; j < N; j++)
        {
            cout << ps[i][j] << " ";
        }
    }
    cout << "\n";
    */
    long long int res = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            int x1 = compressed[i].first;
            int y1 = compressed[i].second;
            int x2 = compressed[j].first;
            int y2 = compressed[j].second;
            //cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
            int a = prefixsum(0, min(y1, y2), min(x1, x2), max(y1, y2));
            int b = prefixsum(max(x1, x2), min(y1, y2), N - 1, max(y1, y2));
            //cout << a << " " << b << "\n\n";
            res += prefixsum(0, min(y1, y2), min(x1, x2), max(y1, y2)) * prefixsum(max(x1, x2), min(y1, y2), N - 1, max(y1, y2));
        }
    }
    res++;
    cout << res << "\n";
    return 0;
}