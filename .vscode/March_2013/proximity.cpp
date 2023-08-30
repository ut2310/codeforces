/*
USER: ut23101
LANG: C++17
TASK: crazy
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
int N, K;
int main()
{
    freopen("proximity.in", "r", stdin);
	freopen("proximity.out", "w", stdout);
    cin >> N >> K;
    map<int, vector<int>> pos;
    vector<int> crowded;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        if(pos.count(temp) == 0)
        {
            vector<int> v;
            v.push_back(i);
            pos.insert(make_pair(temp, v));
        }
        else
        {
            if(i - pos[temp][pos[temp].size() - 1] <= K)
            {
                crowded.push_back(temp);
            }
            pos[temp].push_back(i);
        }
    }
    if(crowded.size() == 0)
    {
        cout << -1;
    }
    else
    {
        int max = *max_element(crowded.begin(), crowded.end());
        cout << max;
    }

}