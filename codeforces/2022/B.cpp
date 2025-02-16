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
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        ll curr = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            curr += a[i];
        }
        sort(a.begin(), a.end());
        ll res = (curr + x - 1)/x;
        res = max(res, a[n - 1]);
        cout << res << "\n";
        
    }
}