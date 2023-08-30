/*
USER: ut23101
LANG: C++17
TASK: closest_cow
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
int K, M, N, group[MAXN];
vector<pair<int, int>> grass;
vector<int> opposing;
vector<pair<int, int>> ep;
int find 
int optimal_cow_placement(int l, r)
{
    int left = l;
    int right = l + (r - l)/2;
    
}
int main()
{
    cin >> K >> M >> N;

    for(int i = 0; i < K; i++)
    {
        int a, b; cin >> a >> b;
        grass.push_back(make_pair(a, b));
        ep.push_back(make_pair(a, b));
    }
    for(int i = 0; i < M; i++)
    {
        int a; cin >> a;
        opposing.push_back(a);
        ep.push_back(make_pair(a, -1));
    }
    sort(ep.begin(), ep.end());

    vector<int> onecowintervals(M + 1);
    vector<int> twocowintervals(M + 1);
    for(int i = 0; i < ep.size(); i++)
    {
        if(ep[i].second == -1)
        {
            
        }
    }
    
}