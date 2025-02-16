using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(2 * n);
        ll cnt = 0;
        for(int i = 0; i < 2 * n; i++){
            cin >> a[i];
            if(a[i] == 1){
                cnt++;
            }
        }
        ll res1 = 0;
        if(cnt <= n){
            res1 = cnt;
        }
        else{
            res1 = 2 * n - cnt;
        }
        ll res2 = 0;
        if(cnt % 2 == 1){
            res2 = 1;
        }
        cout << res2 << " " << res1 << "\n";
    }
}