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
ll dp[70000][18];
ll g[18][18];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; 
    cin >> t;
    while(t-->0) {
        ll n; cin >> n;
        vector<string> a(n);
        vector<string> b(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(a[i] == a[j] || b[i] == b[j])
                {
                    g[i][j] = 1;
                    g[j][i] = 1;
                }
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i < (1<<n); i++) {
        //for(int i = 1; i <= 3; i++) {
            ll v = log2(i);
            if(ceil(log2(i)) == v) {
                dp[i][v] = 1;
                //cout << i << " " << v << "\n";
            } else {
                for(int j = 0; j < n; j++) { // v
                    //cout << j << "\n";
                    if((i&(1<<j)) != 0) {
                        //cout << j << "\n";
                        ll exclude = i - (1<<j);
                        //cout << exclude << "\n";
                        for(int k = 0; k < n; k++) //v_0
                        {   
                            //cout << k << " " << exclude << "\n";
                            if((exclude&(1<<k)) != 0) {
                                //cout << k << " " << exclude << "\n";
                                if(dp[exclude][k] == 1 && g[k][j] == 1) {
                                    dp[i][j] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        /*for(int i = 0; i < (1<<n); i++) {
            for(int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/
        ll res = 0;
        for(int i = 1; i < (1<<n); i++) {
            for(int j = 0; j < n; j++) {
                ll count = 0;
                ll k = i;
                if(dp[i][j] == 1) {
                    while(k) {
                        count += k&1;
                        k >>= 1;
                    }
                    res = max(count, res);
                }
            }
        }
        cout << (n-res) << "\n";
        for(int i = 0; i < (1<<n); i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j =0; j < n; j++)
            {
                g[i][j] = 0;
            }
        }
    }
}