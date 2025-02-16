using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 500005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> adj[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n + 1);
        for(int i = 1; i<= n; i++){
            cin >> a[i];
        }
        set<ll> res;
        for(int i = 0; i < n - 1; i++){
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(a[u] == a[v]){
                res.insert(a[u]);
            }
        }
        set<ll> track;
        for(int i = 1; i <= n; i++){
            for(auto j: adj[i]){
                if(track.count(a[j]) > 0){
                    res.insert(a[j]);
                }
                else{
                    track.insert(a[j]);
                }
            }
            track.clear();
        }
        string final_res = "";
        for(int i = 1; i<= n; i++){
            if(res.count(i) > 0){
                final_res.push_back('1');
            }
            else{   
                final_res.push_back('0');
            }
        }
        cout << final_res << "\n";
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
    }
}