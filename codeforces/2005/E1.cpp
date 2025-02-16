using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define vl vector<ll>
#define vb vector<bool>
int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll l, n, m; cin >> l >> n >> m;
        vector<ll> a(l);
        set<ll> elements;
        for(int i = 0; i < l; i++){
            cin >> a[i];
        }
        vector<vl> b(n, vl(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> b[i][j];
            }
        }
        vector<vector<vb>> dp(n, vector<vb> (m, vb(l)));
        set<ll> curr;
        for(int i = n - 1; i >= 0; i--){
            curr.insert(b[i][m - 1]);
            for(int j = 0; j < l; j++){
                if(curr.count(a[j]) > 0){
                    dp[i][m - 1][j] = 1;
                }
                else{
                    dp[i][m - 1][j] = 0;
                }
            }
        }
        curr.clear();
        for(int i = m - 1; i >= 0; i--){
            curr.insert(b[n - 1][i]);
            for(int j = 0; j < l; j++){
                if(curr.count(a[j]) > 0){
                    dp[n - 1][i][j] = 1;
                }
                else{
                    dp[n - 1][i][j] = 0;
                }
            }
        }
    }
}