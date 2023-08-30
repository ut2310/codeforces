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
#define MAXN 11
int N, output;
vector<pair<int, int>> coord;
bool visited[MAXN];
int ar[MAXN];
void display()
{
    for(int i = 0; i < N; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}
bool valid()
{
    if(coord[ar[0]].first != 0 && coord[ar[0]].second != 0)
    {
        return false;
    }
    for(int i = 1; i < N; i++)
    {
        if(coord[ar[i]].first == coord[ar[i - 1]].first || coord[ar[i]].second == coord[ar[i - 1]].second)
        {
            continue;
        }
        return false;
    }
    if(coord[ar[N - 1]].first == 0 || coord[ar[N - 1]].second == 0)
    {
        return true;
    }
    return false;
}
void recur(int index)
{
    if(index == N)
    {
        if(valid())
        {
            //display();
            output++;
        }
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            ar[index] = i;
            recur(index + 1);
            visited[i] = 0;
        }
        
    }
}
int main()
{
    freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        coord.push_back(make_pair(a, b));
    }
    recur(0);
    cout << output;
}

