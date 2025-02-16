using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
vector<ll> get_divisors(ll x)
{
    vector<ll> res;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            res.push_back(i);
            if(i != x/i){
                res.push_back(x/i);
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        ll n; cin >> n;
        if(n == 0){
            break;
        }

        vector<ll> label(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> label[i];            
        }
        vector<pair<ll, ll>> next(n + 1);
        vector<pair<ll, ll>> prev(n + 1);
        for(int i = 0; i < n - 1; i++){
            ll u, v, w; cin >> u >> v >> w;
            next[u] = make_pair(v, w);
            prev[v] = make_pair(u, w);
        }
        ll start = -1;
        for(int i = 1; i <= n; i++){
            if(prev[i].first == 0 && prev[i].second == 0){
                start = i;
            }
        }
        map<ll, ll> mp;
        mp[start] = 1;
        vector<ll> dp(n + 1);
        ll curr = start;
        ll track = 1;
        while(!next[curr].first == 0 || !next[curr].second == 0){
            track++;
            mp[next[curr].first] = track;
            dp[track] = dp[track - 1] + next[curr].second;
            curr = next[curr].first;
        }
        // for(int i = 1; i <= n; i++){
        //     cout << dp[mp[i]] << " " << mp[i] << "\n";
        // }
        map<ll, vector<ll>> gcd_case;
        for(int i = 1; i <= n; i++){
            vector<ll> temp = get_divisors(label[i]);
            for(auto j: temp){
                if(gcd_case.count(j) == 0){
                    gcd_case[j] = vector<ll>();
                    gcd_case[j].push_back(mp[i]);
                }
                else{
                    gcd_case[j].push_back(mp[i]);
                }
            }
        }
        ll res = 0;
        for(auto i: gcd_case){
            // cout << i.first << ": ";
            // for(auto j: i.second){
            //     cout << j << " ";
            // }
            // cout << "\n";
            ll curr_min = *min_element(i.second.begin(), i.second.end());
            ll curr_max = *max_element(i.second.begin(), i.second.end());
            res = max(res, (dp[curr_max] - dp[curr_min]) * i.first); 
        }
        cout << res << "\n";
    }
}