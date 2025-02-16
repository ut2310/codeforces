using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<pair<ll, ll>> a(n);
        for(int i  = 0; i < n; i++){
            ll s, t; cin >> s >> t;
            a[i] = {s + t, t};
        }
        ll curr = 0;
        sort(a.begin(), a.end());
        vector<pair<ll, ll>> dp(n); //max number of jobs completed, earliest time completed, largest job
        priority_queue<ll> pq;
        dp[0] = {1, a[0].ss};
        pq.push(a[0].ss);
        for(int i = 1; i < n; i++){
            if(dp[i - 1].ss + a[i].ss <= a[i].ff){
                dp[i] = {dp[i - 1].ff + 1, dp[i - 1].ss + a[i].ss};
                pq.push(a[i].ss);
            }
            else{
                ll x = pq.top();
                if(a[i].ss < x){
                    dp[i] = {dp[i - 1].ff, dp[i - 1].ss - x + a[i].ss};
                    pq.pop();
                    pq.push(a[i].ss);
                }
                else{
                    dp[i] = dp[i - 1];
                }
            }
        }
        cout << dp[n - 1].ff << "\n";
    }
}