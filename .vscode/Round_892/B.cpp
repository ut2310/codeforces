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
ll t, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        ll minumum = 1e16;
        ll res = 0;
        ll other = 1e16;
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            vector<ll> track;
            for(int i = 0; i < m; i++)
            {
                ll temp; cin >> temp;
                track.push_back(temp);

            }
            sort(track.begin(), track.end());
            res += track[1];
            if(track[0] < minumum)
            {
                minumum = track[0];
            }
            if(track[1] < other)
            {
                other = track[1];
            }
        }
        res = res - other + minumum;
        cout << res << "\n";
    }
}