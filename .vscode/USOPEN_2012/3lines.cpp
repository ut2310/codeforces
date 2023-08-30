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
#define MAXN 50005
vector<pair<int, int>> points;
int N;
bool check()
{
    set<int> temp;
    set<int> temp2;
    map<int, vector<int>> xtoy;
    map<int, int> ycount;
    for(int i = 0; i < N; i++)
    {
        if(xtoy.count(points[i].first) == 0)
        {
            vector<int> temp; temp.push_back(points[i].second);
            xtoy.insert(make_pair(points[i].first, temp));
        }
        else
        {
            xtoy[points[i].first].push_back(points[i].second);
        } 
        if(ycount.count(points[i].second) == 0)
        {
            ycount.insert(points[i].second, 1);
        } 
        else
        {
            ycount[points[i].second]++;
        }
    }
    for(int i = 0; i < N; i++)
    {
        temp.insert(points[i].first);
        temp2.insert(points[i].second);
    }
    if(temp.size() <= 3)
    {
        return true;
    }
    else
    {
        for(int x: temp)
        {
            map<int, int> temp;
            int distinct = temp2.size();
            for(int y: xtoy[x])
            {
                if(temp.count(y) == 0)
                {
                    temp.insert(make_pair(y, 1));
                }
                else
                {
                    temp[y]++;
                }
            }
            for(auto e: temp)
            {
                if(e.second == ycount[e.first])
                {
                    distinct--;
                }
            }
            if(distinct <= 2)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        points.push_back(make_pair(a, b));
    }
    bool flag1 = check();
    for(int i = 0; i < N; i++)
    {
        auto x = points[i];
        points.push_back(make_pair(x.second, x.first));
    }
    bool flag2 = check();
    if(flag1 || flag2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}