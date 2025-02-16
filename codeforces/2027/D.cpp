using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<ll> a(n + 1);
        vector<ll> ps(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            ps[i] = a[i] + ps[i - 1];
        }
        ll best = -1;
        vector<ll> b(m);
        for(int i = 0; i < m; i++){
            cin >> b[i];
            best = max(best, b[i]);
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(a[i] > best){
                flag = false;
            }
        }
        sort(b.begin(), b.end());
        //the cost becomes the index of the element
        if(flag){
            vector<ll> dp(n + 1);
            dp[n] = lower_bound(b.begin(), b.end(), a[n]) - b.begin();
            //cout << dp[n] << " ";
            for(int i = n - 1; i >= 1; i--){
                dp[i] = 1e9;
                for(int j = 0; j < m; j++){
                    b[j] += ps[i - 1];
                }
                for(ll j = 0; j < m; j++){
                    auto index = upper_bound(ps.begin() + i, ps.end(), b[j]);
                    //from i to index we get what we want with b[j]
                    //cout << i << " " << j << " " << index - ps.begin() << " " << b[j] << "\n";
                    if(index == ps.end()){
                        dp[i] = min(dp[i], j);
                    }
                    else if(index - ps.begin() - 1 >= i){
                        dp[i] = min(dp[i], j + dp[index - ps.begin()]);
                    }
                }
                for(int j = 0; j < m; j++){
                    b[j] -= ps[i - 1];
                }//i, [i, i + 1], [i, i + 2], [i, n] ps[n] - ps[i - 1]
                // if(i <= 5){
                //     cout << dp[i] << " ";
                // }
                //cout << dp[i] << " ";
            }
            //cout << "\n";
            cout << dp[1] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}