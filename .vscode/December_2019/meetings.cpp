/*
USER: ut23101
LANG: C++17
TASK: meetings
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
#define MAXN 50005
struct cow
{
    int weight, pos, dir;
    bool operator<(const cow& y) const { return pos < y.pos; }
};
int N, L;
int main()
{
    cin >> N >> L;
    int total_weight = 0;  
    int T = 0;
    vector<cow> input;
    for(int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        input.push_back({a, b, c});
        total_weight += a;
    }    
    if(total_weight % 2 == 1)
    {
        total_weight++;
    }
    sort(input.begin(), input.end());
    vector<pair<int, int>> arrival; //stores arrival time, direction
    for(int i = 0; i < N; i++)
    {
        if(input[i].dir == -1)
        {
            arrival.push_back(make_pair(input[i].pos, input[i].dir));
        }
        else
        {
            arrival.push_back(make_pair(L - input[i].pos, input[i].dir));
        }
    }
    sort(arrival.begin(), arrival.end());
    int cl = 0;//counter from left
    int cr = N - 1;//counter from right
    int current_weight = 0;
    vector<int> arrleft;
    vector<int> arrright;
    for(int i = 0; i < N; i++)
    {
        if(arrival[i].second == -1)
        {
            if(current_weight < total_weight/2)
            {
                current_weight += input[cl].weight;
                cl++;
            }
            if(current_weight >= total_weight/2)
            {
                T = arrival[i].first;
                break;
            }
            arrleft.push_back(arrival[i].first);
        }
        else
        {
            if(current_weight < total_weight/2)
            {
                current_weight += input[cr].weight;
                cr--;   
            }
            if(current_weight >= total_weight/2)
            {
                T = arrival[i].first;
                break;
            }
            arrright.push_back(arrival[i].first);
        }
    }
    int p1 = 0;
    int p2 = 
}

/*
left = last 1 that is farthest away from the position of -1(should be in 2 * T range)
right = first 1 that is left to the position of the -1

For all the cows from left to right in -1 set other than the first -1
    while location of right + 1 < location of cow i
        right++
    while location of (left) + 2 * T < location of cow i
        left++
    if(left <= right)
        res += right - left + 1
*/
