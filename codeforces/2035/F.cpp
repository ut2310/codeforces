using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 2005
#define ALPHABETSIZE 26
vector<ll> adj[MAXN];
ll dfs(ll p, ll v, vector<ll> &track, vector<ll> &ops, ll mid) //returns the number of extra operations you need for subtree v
{
    ll curr = ops[v] - track[v];
    ll exops = 0;
    
    for(auto u: adj[v]){
        if(p != u){
            exops += dfs(v, u, track, ops, mid); 
        }
    }
    if(curr < 0){
        return abs(curr) + exops;
    }
    else{
        exops -= curr;
        if(exops < 0 && (exops) % 2 != 0){
            return 1;
        }
        return max(0LL, exops);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, x; cin >> n >> x;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++){
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = false;
        ll res = 1e18;
        for(int i = 1; i <= 2*n; i++){
            ll cnt = 0;
            for(int j = 1; j <= n; j++){
                ll troll = 0;
                if(i >= j){
                    troll++;
                }
                if(i >= j + n){
                    troll++;
                }
                cnt += (a[j] + troll) % 2;
            }
            if(cnt % 2 == 0){
                flag = true;
                ll low = i;
                if(low >= 2*n){
                    low -= 2*n;
                }
                ll high = 1e10 * n + i;
                while(low < high){
                    ll mid = (low + high)/2;
                    ll diff = (mid - i + 2 * n) % (2 * n);
                    mid -= diff;
                    vector<ll> ops(n + 1);
                    ll most = ((i - 1 + n) % n) + 1;
                    for(int j = 1; j <= n; j++){
                        ops[j] = mid/n;
                    }
                    ll constant = (i + n) % n;
                    for(int j = 1; j <= constant; j++){
                        ops[j]++;
                    }
                    vector<ll> track(n + 1);
                    for(int i = 1; i <= n; i++){
                        track[i] = a[i];
                    }
                    ll check = dfs(x, x, track, ops, mid);
                    if(check == 0){
                        high = mid;
                    }
                    else{
                        low = mid + 2 * n;
                    }
                }
                
                res = min(res, high);
            }
        }
        if(!flag){
            cout << "-1\n";
        }
        else{
            cout << res << "\n";
        }
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
    }
}