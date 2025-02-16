using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M, fact[MAXN], invfact[MAXN], catalan[MAXN];
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
ll choose(ll a, ll b)
{
    if(a < b)
    {
        return 0;
    }
    else
    {
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
    for(int i = 1; i <= 10000; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
        
    }
    for(int i = 2; i <= 10000; i+=2){
        catalan[i] = choose(i, i/2) * modInverse(i/2 + 1);
        catalan[i] %= M;
        //if(i <= 10) cout << catalan[i] << " ";
    }
    cout << "\n";
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> res(n + 1);
        res[0] = catalan[2*n];
        res[0] %= M;
        //cout << res[0] << " ";
        vector<pair<ll, ll>> track;
        for(int i = 1; i <= n; i++){
            ll l, r; cin >> l >> r;
            auto itr = lower_bound(track.begin(), track.end(), make_pair(l, r));
            track.insert(itr, {l, r});
            //track.push_back({l, r});
            //sort(track.begin(), track.end());
            res[i] = 1;
            vector<ll> a(i + 1);
            a[0] = 2 * n;
            for(int j = 1; j <= i; j++){
                a[j] = track[j - 1].ss - track[j - 1].ff - 1;
            }
            // for(auto j: a){
            //     cout << j << " ";
            // }
            // cout << "\n";
            stack<pair<pair<ll, ll>, ll>> stack; stack.push({{0, 2 * n + 1}, 0});
            for(int i1 = 0; i1 < i; i1++){
                while(!(track[i1].ff > stack.top().ff.ff && track[i1].ss < stack.top().ff.ss)){
                    stack.pop();
                }
                if(track[i1].ff > stack.top().ff.ff && track[i1].ss < stack.top().ff.ss){
                    a[stack.top().ss] -= (track[i1].ss - track[i1].ff + 1);
                    stack.push({{track[i1].ff, track[i1].ss}, i1 + 1});
                }
            }
            // for(auto j: a){
            //     cout << j << " ";
            // }
            //cout << "\n";
            for(int j = 0; j <= i; j++){
                if(a[j] == 0) continue;
                ll temp = catalan[a[j]];
                temp %= M;
                res[i] *= temp;
                res[i] %= M;
            }
        }
        for(int i = 0; i <= n; i++){
            if(res[i] < 0) res[i] += M;
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}