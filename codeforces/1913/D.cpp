using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll M; 
int main()
{
    M = 998244353;
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        stack<pair<ll, ll>> mono;
        vector<ll> track(n); 
        vector<ll> ps(n + 1);
        ps[1] = 1;
        for(int i = 1; i < n; i++){
            ps[i + 1] = ps[i];
            if(a[i - 1] > a[i]) ps[i + 1]++;
        }
        for(int i = 0; i < n; i++){
            bool flag = false;
            while(mono.size() > 0){
                auto curr = mono.top();
                if(curr.ff < a[i]){
                    track[i] = curr.ss;
                    flag = true;
                    break;
                }
                mono.pop();
            }
            if(!flag){
                track[i] = -1;
            }
            mono.push({a[i], i});
        }
        // for(int i = 0; i < n; i++){
        //     cout << track[i] << " ";
        // }
        // cout << "\n";
        vector<ll> dp(n); dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = dp[i - 1];
            dp[i] += ps[i] - ps[track[i] + 1];
            if(track[i] != -1){
                dp[i] += dp[track[i]];
            }
            dp[i] %= M; if(dp[i] < 0) dp[i] += M;
        }
        for(int i = 0; i < n; i++){
            cout << dp[i] << " " << track[i] << "\n";
        }
        cout << dp[n - 1] << "\n";
    }
    
}