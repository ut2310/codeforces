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
#define MAXN 100004
int flooded[MAXN], N;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        flooded[i + 1] = 1;
    }   
    flooded[0] = 1; flooded[N] = 1; //for loop from 1- (N - 1) from now once_flag
    vector<int> heights;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp; heights.push_back(temp);
    }
    map<int, vector<int>> track;
    for(int i = 0; i < N; i++)
    {
        if(track.count(heights[i]) == 0)
        {
            vector<int> temp;
            temp.push_back(i + 1);
            track.insert(make_pair(heights[i], temp));
        }
        else
        {
            track[heights[i]].push_back(i + 1);
        }
    }
    int res = 1;
    int maxres = 1;
    for(auto p: track)
    {
        int current_value = p.first;
        for(int e: p.second)
        {
            //cout << p.second.size() << " " << current_value << " " << e << " " << flooded[e + 1] << " " << flooded[e - 1] << "\n";
            flooded[e] = 0;
            if(e != 1 && e != N)
            {
                if(flooded[e - 1] == flooded[e + 1] && flooded[e - 1] == 0)
                {
                    res--;
                }
                else if(flooded[e - 1] == flooded[e + 1] && flooded[e - 1] == 1)
                {
                    res++;
                }
            }
            else if(e == 1)
            {
                if(flooded[e + 1] == 0)
                {
                    res--;
                }
            }
            else
            {
                if(flooded[e - 1] == 0)
                {
                    res--;
                }
            }
        }
        maxres = max(maxres, res);
    }
    cout << maxres;
}