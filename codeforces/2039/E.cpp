using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M;
int main()
{
    M = 998244353;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> ans(n + 1);
        vector<ll> total(n + 1);
        vector<ll> c(n + 1);
        vector<ll> d(n + 1);
        ans[2] = 0; total[2] = 0; c[2] = 1; d[2] = 0;
        for(ll i = 3; i <= n; i++){
            ll temp = d[i - 1] * (d[i - 1] + 1)/2; 
            temp %= M;
            ans[i] = d[i - 1] * (i - 1) - temp;
            ans[i] %= M;
            ans[i] += i * ans[i - 1];
            ans[i] %= M;
            ans[i] -= total[i - 1];
            ans[i] %= M;
            total[i] = total[i - 1] + ans[i - 1];
            total[i] %= M;
            c[i] = 1; d[i] = i - 2;
        }
        ll res = ans[n] + n - 1;
        res %= M;
        if(res < 0) res += M;
        cout << res << "\n";
    }
}