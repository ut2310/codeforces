#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll calc(ll x, vector<ll> &track)
{
    ll res = 0;
    if(x + 1 >= 1 && x + 1 <= n)
    {
        if(track[x] > track[x + 1]) res++;
    }
    if(x - 1 >= 1 && x - 1 <= n)
    {
        if(track[x] < track[x - 1]) res++;
    }
    return res;
}
int main()
{
    cin >> n >> m;
    vector<ll> curr(n + 1);
    vector<ll> track(n + 1);
    for(int i = 1; i <= n; i++)
    {
        ll temp; cin >> temp;
        curr[i] = temp;
        track[temp] = i;
    }
    ll inv = 0;
    for(int i = 1; i < n; i++)
    {
        if(track[i] > track[i + 1])
        {
            inv++;
        }
    }
    cout << inv << "\n";
    for(int i =0; i < m; i++)
    {
        ll a, b; cin >> a >> b;
        if(a != b)
        {
            ll i0 = calc(curr[a], track) + calc(curr[b], track);
            
            track[curr[b]] = a;
            track[curr[a]] = b;
            ll temp = curr[b];
            curr[b] = curr[a];
            curr[a] =  temp;   
            ll i1 = calc(curr[a], track) + calc(curr[b], track);
            inv += (i1 - i0);
        }
        
        cout << (inv + 1) << "\n";
    }

}