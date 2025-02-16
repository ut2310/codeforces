using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
pair<ll, ll> dp[MAXN][MAXN][2];
int main()
{
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 0){
        cout << 0 << "\n";
        return 0;
    }
    sort(a.begin(), a.end());
    ll fp = -1;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            fp = i;
        }
    }
    if(fp == -1){
        ll res = 0;
        for(int i = 0; i < n; i++){
            res += max(0LL, m + a[i]);
        }
        cout << res << "\n";
        return 0;
    }
    for(ll len = 1; len <= n; len++){
        for(ll l = fp; l >= 0; l--){
            if(l + len - 1 >= n){
                continue;
            }
            //look at l to l + len - 1
            if(a[l] <= 0 && a[l + len - 1] <= 0){
                for(int j = l; j <= l + len - 1; j++){
                    dp[l][l + len - 1][0].first += max(0LL, m + a[j]);
                }
                dp[l][l + len - 1][0].second += abs(a[l]);
                dp[l][l + len - 1][1].second += 2 * abs(a[l]);
                dp[l][l + len - 1][1].first = dp[l][l + len - 1][0].first;
                continue;
            }
            if(a[l] >= 0 && a[l + len - 1] >= 0){
                for(int j = l; j <= l + len - 1; j++){
                    dp[l][l + len - 1][1].first += max(0LL, m - a[j]);
                }
                dp[l][l + len - 1][0].second += abs(a[l + len - 1]);
                dp[l][l + len - 1][1].second += 2 * abs(a[l + len - 1]);
                dp[l][l + len - 1][0].first = dp[l][l + len - 1][1].first;
                continue;
            }
            dp[l][l + len - 1][0] = make_pair(1e18, 1e18); //go to left at the end
            // for(int j = l + 1; j < l + len - 1; j++){
            //     dp[j][l + len - 1] + 
            // }
        }
    }
    for(int l = fp; l >= 0; l--){
        for(int r = fp; r < n; r++){
            if(r == l){

            }
        }
    }
}