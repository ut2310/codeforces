#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <numeric>
#include <map> 
 
using namespace std;
 
#define ll long long
#define MAXN 300005
ll dp[MAXN][12];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; 
    cin >> t;
    while(t-->0) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        vector<ll> pref(n+1);
        pref[0] = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            pref[i+1] = pref[i]+a[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = pref[i];
        }
        for(int i = 0; i <= k; i++) {
            dp[0][i] = 0;
            dp[1][i] = a[0];
        }
        /*for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= k; j++) {
                ll m = a[i-1];
                dp[i][j] = pref[i];
                for(ll d = 0; d <= j; d++) {
                    m = min(m, a[i-d-1]);
                    dp[i][j] = min(dp[i][j], (d+1)*m + dp[i-1-d][j-d]);
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << n << " " << k << " " << dp[n][k] << "\n";
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = 0;
            }
            //cout << "\n";
        }
    }
}