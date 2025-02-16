using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll deg[MAXN];
vector<ll> adj[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        for(int i = 0; i < n - 1; i++){
            ll u, v; cin >> u >> v;
            deg[u]++; deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n == 2){
            cout << "0\n";\
            for(int i = 1; i <= n; i++){
                deg[i] = 0;
                adj[i].clear();
            }
            continue;
        }
        vector<ll> leaf;
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1){
                leaf.push_back(i);
            }
        }
        vector<ll> other;
        for(auto j: leaf){
            for(auto i: adj[j]){
                other.push_back(j);
            }
        }
        ll res = leaf.size() * (n - leaf.size());
        ll cnt_p = 0; ll cnt_q = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1) continue;
            ll cnt = 0;
            for(auto j: adj[i]){
                if(deg[j] == 1) cnt++;
            }
            if(cnt == 0){
                cnt_p++;
            }
            else{
                cnt_q += deg[i] - cnt - 1;
            }
        }
        res += cnt_p * cnt_q;
        //look at stuff that are not leaves but connected to leaves and one more thing
        cout << res << "\n";
        for(int i = 1; i <= n; i++){
            deg[i] = 0;
            adj[i].clear();
        }
    }
}