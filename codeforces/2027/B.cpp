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
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<ll> tm(n);
        for(int i = 1; i < n; i++){
            ll cnt = 0;
            for(int j = 0; j < i; j++){
                if(a[j] < a[i]){
                    cnt++;
                }
            }
            tm[i] = cnt;
            //cout << i << " " << cnt << "\n";
        }
        vector<ll> tn(n);
        for(int i = n - 2; i >= 0; i--){
            ll cnt = 0;
            for(int j = i + 1; j < n; j++){
                if(a[j] > a[i]){
                    cnt++;
                }
            }
            tn[i] = cnt;
        }
        ll res = 1e18;
        for(int i = 0; i < n; i++){
            res = min(res, tn[i] + i);
        }
        cout << res << "\n";
    }
}