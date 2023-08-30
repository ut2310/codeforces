/*
USER: ut23101
LANG: C++17
TASK: crossings
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
#define MAXN 100005
vector<pair<int, int>> input;
int intersect(int x1, int y1, int x2, int y2)
{
    if(((x1 < x2) && (y1 < y2)) || ((x1 > x2) && (y1 > y2)))
    {
        return 0;
    }
    return 1;
}
int main()
{
    freopen("crossings.in", "r", stdin);
	freopen("crossings.out", "w", stdout);
    int N; cin >> N;
    vector<int> x;
    vector<int> y;
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        input.push_back(make_pair(a, b));
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(input.begin(), input.end());
    map<int, int> xi;
    map<int, int> yi;
    for(int i = 0; i < N; i++)
    {
        xi[x[i]] = i;
        yi[y[i]] = i;
    }
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        if(xi[input[i].first] == yi[input[i].second])
        {
            counter++;
        }
    }
    cout << counter;
}
//Start: 4:22, 4:52, Start: 8:25