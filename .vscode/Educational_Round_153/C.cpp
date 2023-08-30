using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#define ll long long 
#define MAXN 300005
ll t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<ll> input;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        ll track = input[0];
        ll track2 = 1e9;
        ll res = 0;
        int j = 1;
        while(j < n) 
        {
            if(input[j] < track2 && input[j] > track)
            {
                //cout << j << " " << track2 << "\n";
                track2 = input[j];
                res++;
            }
            track = min(track, input[j]);
            j++;
        }
        cout << res << "\n";
    }
}