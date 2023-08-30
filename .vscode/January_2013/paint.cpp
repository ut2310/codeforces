/*
USER: ut23101
LANG: C++17
TASK: paint
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
void print(vector<pair<int, int>> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second;
    }
    cout << "\n";
}
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first != p2.first)
    {
        return (p1.first - p2.first) < 0;
    }
    return (p1.second - p2.second) > 0;
}
int main()
{
    freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
    cin >> N;
    int current = 0;
    vector<pair<int, int>> intervals;
    for(int i = 0; i < N; i++)
    {
        int a; char b;
        cin >> a >> b;
        if(b == 'R')
        {
            int newp = current + a;
            intervals.push_back(make_pair(current, newp));
            current = newp;
        }
        else
        {
            int newp = current - a;
            intervals.push_back(make_pair(newp, current));
            current = newp;
        }
    }
    vector<pair<int, int>> ep;//event points
    for(int i = 0; i < intervals.size(); i++)
    {
        ep.push_back(make_pair(intervals[i].first, 0));
        ep.push_back(make_pair(intervals[i].second, 1));
    }
    sort(ep.begin(), ep.end(), cmp);
    int cnt = 0;
    int curr = 0;
    int res = 0;
    for(int i = 0; i < ep.size(); i++)
    {
        if(ep[i].second == 0)
        {
            cnt++;
            if(cnt == 2)
            {
                curr = ep[i].first;
            }
        }
        else
        {
            cnt--;
            if(cnt == 1)
            {
                res += ep[i].first - curr;
            }
        }
        
    }   
    cout << res;
}
//Start: 11:00 End: 12:00
//Start: 12:40 End: 12:57