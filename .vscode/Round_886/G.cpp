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
#define MAXN 200005
#define ll long long int
ll t, n;
ll calc(map<ll, ll> mp)
{
    ll res = 0;
    for(auto i: mp)
    {
        res += i.second * (i.second - 1);
    }
    return res;
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        map<ll, ll> x;
        map<ll, ll> y;
        map<ll, ll> pos;
        map<ll, ll> neg;
        for(int i = 0; i < n; i++)
        {
            ll a, b; cin >> a >> b;
            x[a]++;
            y[b]++;
            pos[b - a]++;
            neg[a + b]++;
        }
        ll res = 0;
        res += calc(x);
        res += calc(y);
        res += calc(pos);
        res += calc(neg);
        cout << res << "\n";
    }
}