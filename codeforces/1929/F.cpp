using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 500005
ll subtree[MAXN], M;
pair<ll, ll> adj[MAXN];
ll fact[MAXN], invfact[MAXN], pos[MAXN], value[MAXN];
void get_sizes(ll v)
{
    if(adj[v].first == -1 && adj[v].second == -1){
        subtree[v] = 1;
        return;
    }
    subtree[v] = 1;
    if(adj[v].first != -1){
        get_sizes(adj[v].first);
        subtree[v] += subtree[adj[v].first];
    }
    if(adj[v].second != -1){
        get_sizes(adj[v].second);
        subtree[v] += subtree[adj[v].second];
    }
    return;
}
void dfs(ll v, ll l, ll r)
{
    //cout << v << " " << l << " " << r << "\n";
    if(adj[v].first == -1) pos[v] = l;
    else pos[v] = subtree[adj[v].first] + l;
    if(adj[v].first != -1){
        dfs(adj[v].first, l, subtree[adj[v].first] + l - 1);
    }
    if(adj[v].second != -1){
        dfs(adj[v].second, subtree[adj[v].first] + l + 1, r);
    }
}
ll mod(ll a, ll b)
{
    if(a % b < 0)
    {
        return b + a % b;
    }
    return a % b;
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2);
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    M = 998244353;
    fact[0] = 1;
    invfact[0] = 1;
    for(ll i = 1; i <= 500003; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);

        //if(i <= 10) cout << fact[i] << " " << (fact[i] * invfact[i]) % M << "\n";
        //cout << i << " " << invfact[i] << "\n";
    }
    while(t-->0){
        ll n, C; cin >> n >> C;
        vector<pair<ll, ll>> arr;
        for(int i = 0; i < n; i++){
            ll l, r, val; cin >> l >> r >> val;
            adj[i + 1] = {l, r};
            value[i + 1] = val;
        }
        get_sizes(1);
        dfs(1, 1, n);
        vector<ll> get_pos(n + 2);
        for(int i = 1; i <= n; i++){
            get_pos[pos[i]] = value[i];
        }
        get_pos[0] = 1;
        get_pos[n + 1] = C;
        ll empty = 0; ll less = 1;
        ll res = 1;
        for(int i = 1; i <= n + 1; i++){
            if(get_pos[i] == -1){
                empty++;
            }
            else{
                //values range from less to get_pos[i]
                ll posNum = get_pos[i] - less + 1;
                ll total = empty;
                for(ll i = posNum + total - 1; i >= posNum; i--){
                    res *= i;
                    res %= M;
                }
                //cout << res << " " << invfact[total] << " " << total << " hi\n";
                res *= invfact[total]; res %= M;
                if(res < 0) res += M;
                //cout << posNum << " " << total << " " << res << "\n";

                //posNum + total - 1 choose posNum - 1 (2)
                //posNum + total - 1 * .... posNum

                less = get_pos[i];
                empty = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            adj[i] = {0, 0}; pos[i] = 0; value[i] = 0;
        }
        cout << res << "\n";
    }
    
}