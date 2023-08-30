/*
USER: ut23101
LANG: C++17
TASK: truth
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
#define MAXN 1005
vector<pair<int, char>> adj[MAXN];
int visited[MAXN];
int N, M;
vector<pair<pair<int, int>, char>> edges;
bool impossible = false;
int type[MAXN];
void check(int a, int b, char c)
{
    if(type[a] == type[b] && c == 'L')
    {
        impossible = true;
    }
    if(type[a] != type[b] && c == 'T')
    {
        impossible = true;
    }
}
void ff(int vertice)
{
    visited[vertice] = 1;
    for(auto e: adj[vertice])
    {
        if(visited[e.first] == 1)
        {
            check(vertice, e.first, e.second);
            if(impossible)
            {
                return;
            }
        }
        else
        {
            if(e.second == 'T')
            {
                type[e.first] = type[vertice];
            } 
            else
            {
                type[e.first] = 1 - type[vertice];
            }
            ff(e.first);
        }
    }
}
bool full_check(int count_edges)
{
    for(int i = 0; i < MAXN; i++)
    {
        adj[i].clear();
    }
    //cout << "Check #-1\n";
    //fflush(stdout);
    for(int i = 0; i < count_edges; i++)
    {
        //cout << edges[i].first.first << " " <<  edges[i].first.second << " " << edges[i].second << "\n";
        //fflush(stdout);
        adj[edges[i].first.first].push_back(make_pair(edges[i].first.second, edges[i].second));
        adj[edges[i].first.second].push_back(make_pair(edges[i].first.first, edges[i].second));
    }
    //cout << "Check #0\n";
    //fflush(stdout);
    fill(visited, visited + N + 1, 0);
    fill(type, type + N + 1, -1);
    impossible = false;
    //cout << "Check #1\n";
    //fflush(stdout);
    for(int i = 1; i <= N; i++)
    {
        if(visited[i] == 0)
        {
            type[i] = 0;
            ff(i);
            if(impossible)
            {
                break;
            }
        }
    }
    return !impossible;
}
int main()
{
    freopen("truth.in", "r", stdin);
	freopen("truth.out", "w", stdout);
    cin >> N >> M;
    int res = 0;
    for(int i = 1; i <= N; i++)
    {
        type[i] = -1;
    }
    int low = 0;
    int high = M;
    //cout << M << " \n";
    for(int i = 0; i < M; i++)
    {
        int a, b; char c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(make_pair(a, b), c));
        // cout << a << " " << b << " " << c << "\n";
        // fflush(stdout);

    }
    // for(int i = 0; i < M; i++)
    // {
    //     cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << "\n";
    // }
    while(low < high)
    {
        int mid = (low + high + 1)/2;
        // cout << mid << "\n";
        // fflush(stdout);
        if(full_check(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
        // cout << mid << "\n";
        // fflush(stdout);
    }
    cout << low;
}