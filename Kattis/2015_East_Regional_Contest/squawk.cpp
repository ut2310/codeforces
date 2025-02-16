using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105
#define ALPHABETSIZE 26
vector<ll> adj[MAXN];
int main()
{
    ll n, m, s, t; cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> og(n + 1);
    og[s] = 1;
    vector<ll> cnt(n + 1);
    ll res = 1;
    for(int t1 = 1; t1 <= t; t1++){
        for(int i = 0; i < n; i++){
            cnt[i] = 0;
            for(auto j: adj[i]){
                cnt[i] += og[j];
            }
        }
        res = 0;
        for(int i = 0; i < n; i++){
            //cout << i << " " << cnt[i] << "\n";
            og[i] = cnt[i];
            res += og[i];
        }
        //cout << res << "\n";
    }

    cout << res << "\n";
}