#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll, ll> calc(ll num)
{
    ll i = 0;
    ll track = 1;
    while(track < num)
    {
        track *= 2;
        i++;
    }
    if(track > num) 
    {
        i--;
        track/=2;
    }
    return make_pair(i, track);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> res;
        pair<ll, ll> store = calc(k);
        ll pow2 = store.second;
        ll exp = store.first;
        ll track = 1;
        for(int i = 0; i < exp; i++)
        {
            res.push_back(track);
            track *= 2;
        }
        if(pow2 != k) res.push_back(k - pow2);
        res.push_back(k + 1);
        res.push_back(pow2 * 3);
        pair<ll, ll> store2 = calc(n);
        track *= 2;
        for(int i = exp + 1; i <= store2.first; i++)
        {
            res.push_back(track);
            track *= 2;
        }
        cout << res.size() << "\n";
        for(auto i: res)
        {
            cout << i << " ";
        }
        cout << "\n";


    }
}