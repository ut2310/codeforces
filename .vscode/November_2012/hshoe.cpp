/*
USER: ut23101
LANG: C++17
TASK: hshoe
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
#define MAXN 6
int res, N, visited[MAXN][MAXN];
char arr[MAXN][MAXN];
bool balanced(string s)
{
    if(s.size() % 2 == 1)
    {
        return false;
    }
    for(int i = 0; i < s.size()/2; i++)
    {
        if(s.at(i) == ')')
        {
            return false;
        }
    }
    for(int i = s.size()/2; i < s.size(); i++)
    {
        if(s.at(i) == '(')
        {
            return false;
        }
    }
    return true;
}
void dfs(int x, int y, string current) //ask about pass by reference
{
    //cout << x << " " << y << " " << current << "\n";
    //fflush(stdout);
    if(current.size() > 0)
    {
        if(balanced(current))
        {
            res = max(res, (int)(current.size()));
            return;
        }
    }
    if(visited[x][y] == 1 || x < 0 || x >= N || y < 0 || y >= N)
    {
        return;
    }
    visited[x][y] = 1;
    if(current.size() > 0)
    {
        if(current.at(current.size() - 1) == ')' && arr[x][y] == '(')
        {
            visited[x][y] = 0;
            return;
        }
    }
    current = current + arr[x][y];
    dfs(x - 1, y, current);
    dfs(x + 1, y, current);
    dfs(x, y - 1, current);
    dfs(x, y + 1, current);
    visited[x][y] = 0;
}
int main()
{
    freopen("hshoe.in", "r", stdin);
	freopen("hshoe.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    string initial = "";
    //cout << "Hello";
    dfs(0, 0, initial);
    cout << res;

}
//Start: 1:57