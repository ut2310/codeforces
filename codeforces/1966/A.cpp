#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;;
        vector<ll> a(n);
        map<ll, ll> freq;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        bool flag = false;
        for(auto j: freq)
        {
            if(j.second >= k) flag = true;
        }
        if(flag) cout << k - 1 << "\n";
        else cout << n << "\n";

    }
}