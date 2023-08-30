/*
USER: ut23101
LANG: C++17
TASK: assign
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
#define MAXN 18
int N, K, ans, breed[MAXN];
vector<pair<char, int>> adj[MAXN];
bool check(int id, int x)
{
    for(auto neigh: adj[id])
    {
        char c = neigh.first;
        if(breed[neigh.second] != 0)
        {
            if(c == 'S')
            {
                if(breed[neigh.second] != x)
                {
                    return false;
                }
            }
            else
            {
                if(breed[neigh.second] == x)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void recur(int id)
{
    if(id == N + 1)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= 3; i++)
    {
        if(check(id,i))
        {
            breed[id] = i;
            recur(id + 1);
            breed[id] = 0;
        }
    }
}
int main()
{
    freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int a, b; 
        char c;
        cin >> c >> a >> b;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    /*
    for(int i = 1; i <= N; i++)
    {
        for(auto p: adj[i])
        {
            cout << i << " " << p.second << " " << p.first << " ";
        }
        cout << "\n";
    }
    */
    recur(1);
    cout << ans;
}
//Start: 11:40 End: 11:55, Start: 9:30, End: 