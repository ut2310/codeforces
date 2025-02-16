using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        map<ll, ll> pos;
        pos[a[0]] = 0;
        vector<pair<ll, ll>> dp(n);
        dp[0] = make_pair(1, 1);
        for(int i = 1; i < n; i++){
            if(a[i] - a[i - 1] > 1){
                pos[a[i]] = i;
                dp[i] = make_pair(1, 1);
            }
            else if(a[i] - a[i - 1] == 1){
                pos[a[i]] = i;
                auto get = dp[i - 1];
                if(get.second < k){
                    dp[i] = make_pair(get.first + 1, get.second + 1);
                    
                }
                else if(get.second == k){
                    dp[i] = make_pair(i - pos[a[i] - k + 1] + 1, k);
                }
            }
            else{
                dp[i] = make_pair(dp[i - 1].first + 1, dp[i - 1].second);
            }
        }
        ll res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, dp[i].first);
        }
        cout << res << "\n";
        
    }
}