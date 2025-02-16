using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<pair<ll, ll>> a(n);
        for(int i = 0; i < n; i++){
            ll a1, a2; cin >> a1 >> a2;
            a[i] = (make_pair(a1, a2));
        }   
        set<ll> store;
        for(int i = 0; i < n; i++){
            store.insert(a[i].first);
            store.insert(a[i].second);
        }
        ll cnt = 0;
        map<ll, ll> mp;
        for(auto itr: store){
            mp[itr] = cnt;
            cnt++;
        }
        vector<pair<ll, ll>> res;
        for(int i = 0; i < n; i++){
            res.push_back({mp[a[i].first] + mp[a[i].second], i});
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < n; i++){
            cout << a[res[i].second].first << " " << a[res[i].second].second << " ";
        }
        cout << "\n";
    }
}