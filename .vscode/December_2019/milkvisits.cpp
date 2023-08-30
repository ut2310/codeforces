/*
USER: ut23101
LANG: C++17
TASK: milkvisits
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
int N, M, ff[MAXN], type[MAXN];
vector<int> adj[MAXN];
void dfs(int prnt, int current, int region)
{
    ff[current] = region;
    for(int i: adj[current])
    {
        if(i != prnt)
        {
            if(type[i] == type[current])
            {
                dfs(current, i, region);
            }
        }
    }
}
int main()
{
    freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> N >> M;
    string s; cin >> s;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; i++)
    {
        if(s.at(i) == 'G')
        {
            type[i + 1] = 1;
        }
        else
        {
            type[i + 1] = 0;
        }
    }
    int cnt = 1;
    for(int i = 1; i <= N; i++)
    {
        if(ff[i] == 0)
        {
            dfs(i, i, cnt);
            cnt++;
        }
    }
    string res = "";
    for(int i = 0; i < M; i++)
    {
        int a, b; char c;
        cin >> a >> b >> c;
        if(ff[a] != ff[b])
        {
            res.append("1");
        }
        else
        {
            if(c == s.at(a - 1))
            {
                res.append("1");
            }
            else
            {
                res.append("0");
            }
        }
    }
    cout << res;
}
