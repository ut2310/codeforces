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

int main()
{
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll M = 1e9 + 7;
    vector<ll> dp(x + 1);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            if(a[j] > i) break;
            dp[i] += dp[i - a[j]];
            dp[i] %= M;
        }
    }
    if(dp[x] < 0) dp[x] += M;
    cout << dp[x] << "\n";
}