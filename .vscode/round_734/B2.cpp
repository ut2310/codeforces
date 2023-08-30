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
#define MAXN 200005
int t, N, K, res[MAXN];
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N >> K;
        vector<pair<int, int>> input;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            input.push_back(make_pair(temp, i));
        }
        sort(input.begin(), input.end(), comp);
        int counter = 0;
        int color = 1;
        for(int i = 0; i < N; i++)
        {
            if(i != 0)
            {
                if(input[i].first != input[i - 1].first)
                {
                    counter = 0;
                }
            }
            if(counter < K)
            {
                counter++;
                res[input[i].second] = color;
                color++;
                if(color > K)
                {
                    color = 1;
                }
            }
            else
            {
                res[input[i].second] = 0;
            }
        }
        for(int i = N - 1; i >= 0; i--)
        {
            if(res[input[i].second] == K)
            {
                break;
            }
            else
            {
                res[input[i].second] = 0;
            }
        }
        for(int i = 0; i < N; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}