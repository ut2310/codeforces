using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M;
ll dp2[MAXN];
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
int main()
{
    // freopen("poetry.in","r",stdin);
    // freopen("poetry.out", "w", stdout);
    M = 1000000007;
    ll n, m, k; cin >> n >> m >> k;
    vector<pii> words(n + 1);
    vector<vector<int>> type(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> words[i].first >> words[i].second;
        type[words[i].ss].push_back(words[i].ff);        
    }
    dp2[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(i - words[j].first >= 0){
                dp2[i] += dp2[i - words[j].first];
                dp2[i] %= M;
            }
        }
    }
    map<char, ll> mp;
    for(int i = 1; i <= m; i++){
        char c; cin >> c;
        mp[c]++;
    }
    ll res = 1;
    for(auto j: mp){
        ll num = j.second;
        ll curr = 0;
        for(int i = 1; i <= n; i++){
            ll rn = 0;
            for(auto len: type[i]){
                rn += dp2[k - len];
                rn %= M;
            }
            rn = power(rn, num);
            curr += rn; curr %= M;
        }
        res *= curr;
        res %= M;
    }
    if(res < 0) res += M;
    cout << res << "\n";
    

}