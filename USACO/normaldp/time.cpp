using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[1005][2005];
int main()
{
    freopen("time.in","r",stdin);
    freopen("time.out", "w", stdout);
    ll n, m, c; cin >> n >> m >> c;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> oadj(n + 1);
    for(int i = 1; i <= m; i++){
        ll a1, b; cin >> a1 >> b;
        adj[a1].push_back(b);
        oadj[b].push_back(a1);
    }   
    //cerr << "chicken\n";
    for(int i = 2000; i >= 0; i--){
        for(int j = 2; j <= n; j++){
            dp[j][i] = -1e9;
        }
    }
    for(auto v: oadj[1]){
        dp[v][2000] = -4001 * c;
        //cerr << v << " " << c << " " << dp[v][2000] << "\n";
    }  
    for(int i = 1999; i >= 0; i--){
        for(int j = 1; j <= n; j++){
            for(auto v1: adj[j]){
                dp[j][i] = max(dp[j][i], dp[v1][i + 1] - (c * (2 * i + 1)) + a[v1]);
            }
        }
    }
    cout << dp[1][0] << "\n";
}