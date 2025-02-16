using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
set<ll> adj[MAXN];
ll subtree[MAXN];
map<ll, vector<ll>> etov;
ll vtoe[MAXN];
void dfs2(ll v, ll p)
{
    ll size = 1;
    for(auto i: adj[v]){
        dfs2(i, v);
        size += subtree[i];
    }
    subtree[v] = size;
    return;
}
void dfs(ll v, ll p)
{
    ll prev = -1;
    for(auto i: adj[v]){
        etov[i].push_back(i - 1);
        etov[i].push_back(subtree[i] + i - 1);
        vtoe[i - 1]+=1;
        vtoe[subtree[i] + i - 1] += 1;
        dfs(i, v);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, w; cin >> n >> w;
        vector<ll> parent(n + 5);
        for(int i = 2; i <= n; i++){
            cin >> parent[i];
            adj[parent[i]].insert(i);
        }
        //want leaves each edge will go to
        ll res = w * n;
        vector<pair<ll, ll>> track(n + 1); //tracks 
        ll soFar = 0;
        dfs2(1, 1);
        dfs(1, 1);
        ll cnt = n - 2;
        for(int i = 0; i < n - 1; i++){
            ll x, y; cin >> x >> y; //t_x = y care about which paths x impacts 
            soFar += y;
            res -= cnt * y; //all paths which don't have this edge in have a new maximum
            //update paths which do have this edge. if they complete it, you already know, otherwise they state the same
            ll n1 = etov[x][0];
            ll n2 = etov[x][1];
            //cout << x << " " << n1 << " " << vtoe[n1] << " " << n2 << " " << vtoe[n2] << "\n";
            track[n1] = make_pair(track[n1].first + 1, track[n1].second + y);
            track[n2] = make_pair(track[n2].first + 1, track[n2].second + y);
            if(track[n1].first == vtoe[n1]){
                res += soFar - w;
                cnt--;
            }
            if(track[n2].first == vtoe[n2]){
                res += soFar - w;
                cnt--;
            }
            cout << res << " ";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            subtree[i] = 0;
            vtoe[i] = 0;
        }
        etov.clear();

    }
}