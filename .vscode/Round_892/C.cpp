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
ll t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        ll res = 0;
        for(int i = n - 2; i >= 0; i--)
        {
            ll track = 0;
            track +=  (i) * (i + 1) * (2 * i + 1)/6;
            for(int j = i + 1; j <= n; j++)
            {
                track += j * (i + 1 + n - j);
            }
            if((i + 1 + n) % 2 == 0)
            {
                track -= (i + 1 + n) * (i + 1 + n)/4;
            }
            else
            {
                ll x = (i + 1 + n)/2;
                track -= x * (x + 1);
            }
            res = max(res, track);
        }
        cout << res << "\n";
    }
}