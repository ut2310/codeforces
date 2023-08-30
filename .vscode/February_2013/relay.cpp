/*
USER: ut23101
LANG: C++17
TASK: relay
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
int N;
#define MAXN 1005
int visited[MAXN];
map<int, int> function;
bool loopy(int a)
{
    visited[a] = true;
    while(!visited[function[a]])
    {
        if(function[a] == 0)
        {
            return false;
        }
        a = function[a];
        visited[a] = true;
    }
    return true;
}
int main()
{
    freopen("relay.in", "r", stdin);
	freopen("relay.out", "w", stdout);
    cin >> N; 
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        function[i + 1] = temp;
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        bool flag = loopy(i);
        if(!flag)
        {
            cnt++;
        }
        std::fill(visited, visited+N + 1, 0);

    }
    cout << cnt;
}