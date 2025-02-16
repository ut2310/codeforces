using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
ll dp[MAXN];
ll M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M = 1000000007;
    ll t; cin >> t;
    vector<ll> n(t);
    vector<ll> k(t);
    for(int i = 0; i < t; i++){
        cin >> n[i];
    }
    for(int i = 0; i < t; i++){
        cin >> k[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= 100005; i++){
        dp[i] = dp[i - 1] * 2;
        dp[i] %= M;
        if(dp[i] < 0) dp[i] += M;
    }
    for(int i = 0; i < t; i++){
        cout << dp[k[i]] << "\n";
    }

}