using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a.begin(), a.end());
        ll res = 1e9;
        ll j = n - 1;
        for(int i = 0; i < n - 2; i++){
            ll curr = i;
            auto itr = lower_bound(a.begin(), a.end(), a[i] + a[i + 1]);
            if(itr != a.end()){
                curr += n - 1 - (itr-a.begin()) + 1;
                
            }
            res = min(res, curr); //first index which is greater than or equal to it
        }
        cout << res << "\n";
    }
}