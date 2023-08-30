/*
USER: ut23101
LANG: C++17
TASK: cowntagion
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
#define MAXN 100005
int N;
int adj[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b;
        adj[a]++;
        adj[b]++;
    }
    int res = 0;
    for(int i = 1; i <= N; i++)
    {
        if(i == 1)
        {
            res += ceil(log2(adj[i] + 1));
        }
        else
        {
            res += ceil(log2(adj[i]));
        }
    }
    res += N - 1;
    cout << res;
}

