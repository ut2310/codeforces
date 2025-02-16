using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 400005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll cat[MAXN], M, fact[MAXN], invfact[MAXN];
vector<ll> adj[MAXN];
ll mod(ll a, ll b)
{
    if(a % b < 0){
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
ll choose(ll a, ll b)
{
    if(a < b){
        return 0;
    }
    else{
        ll res = mod((fact[a] * invfact[b]), M);
        res = mod((res * invfact[a - b]), M);
        return res;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    M = 998244353;
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 400003; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
    }
    cat[0] = 1;
    for(int i = 1; i <= 200002; i++){
        cat[i] = modInverse(i + 1) * choose(2 * i, i);
        cat[i] %= M;
    }
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<pair<ll, ll>> a;
        bool flag = false;
        for(int i = 0; i < m; i++){
            ll x, y; cin >> x >> y;
            a.push_back({x, y});
            if(a[i].first == 1 && a[i].second == n){
                flag = true;
            }
        }
        if(!flag) a.push_back({1, n});
        //if one segment is a subset of another segment (1, n) (3, 5), (x,  y)

        sort(a.begin(), a.end(), [](pair<ll, ll> v, pair<ll, ll> b){
            if(v.first != b.first) return v.first < b.first;
            return v.second > b.second;
        });
        pair<ll, ll> curr = {1, n};
        stack<pair<pair<ll, ll>, ll>> track; track.push({{1, n}, 0});
        vector<ll> res(a.size());
        for(int i = 0; i < a.size(); i++){
            res[i] = a[i].ss - a[i].ff;
        }
        for(int i = 1; i < a.size(); i++){
            while(!(a[i].first >= track.top().ff.ff && a[i].second <= track.top().ff.ss)){
                track.pop();
            }
            res[track.top().ss] -= a[i].second - a[i].first;
            track.push({{a[i].first, a[i].second}, i});
        }
        ll ans = 1;
        for(int i = 0; i < res.size(); i++){
            assert(res[i] >= 0);
            ans *= cat[res[i]];
            ans %= M;
        }
        if(ans < 0) ans += M;
        cout << ans << "\n";
    }
}