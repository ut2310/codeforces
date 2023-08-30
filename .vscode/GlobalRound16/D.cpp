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
#define MAXN 305
int t, n, m, placed[MAXN];
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m;
        vector<int> input;
        vector<int> sorted;
        for(int i = 0; i < m; i++)
        {
            int temp; cin >> temp; input.push_back(temp); sorted.push_back(temp);
        }
        sort(sorted.begin(), sorted.end());
        map<int, int> track;
        for(int i = 0; i < m; i++)
        {
            if(i == m - 1 || sorted[i] != sorted[i + 1])
            {
                track.insert(make_pair(sorted[i], i));
            }
        }
        long long int res = 0;
        fill_n(placed, m, -1);
        for(int i = 0; i < m; i++)
        {
            placed[track[input[i]]] = input[i];
            for(int j = 0; j < track[input[i]]; j++)
            {
                if(placed[j] != -1)
                {
                    res++;
                }
            }
            track[input[i]]--;
        }
        cout << res << "\n";

    }
}