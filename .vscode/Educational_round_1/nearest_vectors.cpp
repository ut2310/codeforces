using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <cmath>
bool comp(pair<long double, int> p1, pair<long double, int> p2)
{
    return p1.first < p2.first;
}
int main()
{
    int N;
    cin >> N;
    vector<pair<long double, int>> angles;
    //setprecision(18);
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        long double temp = atan2(b, a) * 180/3.14159265358979323846;
        if(temp < 0)
        {
            temp = 360 + temp;
        }
        angles.push_back(make_pair(temp, i + 1));
    }
    sort(angles.begin(), angles.end(), comp);
    long double min = 1000;
    int ans = -1;
    for(int i = 1; i < angles.size(); i++)
    {
        if(abs(angles[i].first - angles[i - 1].first) < min)
        {
            min = abs(angles[i].first - angles[i - 1].first);
            ans = i;
        }
        //cout << angles[i - 1].second << " " << angles[i].second << " " << abs(angles[i].first - angles[i - 1].first) << "\n";
    }
    //cout << angles[0].second << " " << angles[N - 1].second << " " << abs(angles[0].first - angles[N - 1].first) << "\n";
    if(abs(angles[0].first + 360 - angles[angles.size() - 1].first) < min)
    {
        min = abs(angles[0].first - angles[angles.size() - 1].first);
        ans = 0;
        cout << angles[0].second << " " << angles[angles.size() - 1].second;
       
    }
    else
    {
        cout << angles[ans].second << " " << angles[ans - 1].second;
    }
 
}
