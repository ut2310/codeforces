using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
map<ll, vector<ll>> mp;
map<ll, ll> dp;
void recur(ll curr)
{
    ll res = curr;
    if(mp.count(curr) == 0){
        dp[curr] = curr;
        return;
    }
    else if(dp.count(curr) > 0){
        return;
    }
    for(auto j: mp[curr]){
        recur(j);
        res = max(res, dp[j]);
    }
    dp[curr] = res;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i > 1){
                if(mp.count(a[i] + i) > 0){
                    mp[a[i] + i].push_back(a[i] + 2 * i - 1);
                }
                else{
                    vector<ll> temp;
                    mp[a[i] + i] = temp;
                    mp[a[i] + i].push_back(a[i] + i + i - 1);
                }
            }
            
        }
        // for(auto i: mp){
        //     cerr << i.first << " ";
        //     for(auto j: i.second){
        //         cerr << j << " ";
        //     }
        //     cerr << "\n";
        // }
        recur(n + 1);
        //answer should be dp[]
        cout << dp[n + 1] - 1 << "\n";
        mp.clear();
        dp.clear();
    }
}