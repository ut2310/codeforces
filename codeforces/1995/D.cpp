using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll k; cin >> k;
        vector<ll> a(k);
        for(int i = 0; i < k; i++){
            cin >> a[i];
            for(int j = 0; j < a[i] - 1; j++){
                ll x; cin >> x;
            }
        }
        sort(a.begin(), a.end());
        vector<ll> dp(k);
        dp[0] = a[0];
        for(int i = 1; i < k; i++){
            dp[i] = a[i];
            ll addOn = 0;
            for(int j = 20; j >= 0; j--){
                if(!(dp[i] & (1 << j))){
                    addOn += (1 << j);
                    if(addOn > dp[i - 1]){
                        addOn -= (1 << j);
                    }
                } 
            }
            dp[i] += addOn;
        }
        cout << dp[k - 1] << "\n";
    }
}