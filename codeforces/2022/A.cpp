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
        ll n, r; cin >> n >> r;
        vector<ll> a(n);
        ll res = 0;
        ll left = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            res += (a[i]/2) * 2;
            r -= a[i]/2;
            if(a[i] % 2 != 0){
                left++;
            }
        }
        if(2 * r - left >= left){
            res += left;
        }
        else{
            res += 2 * r - left;
        }
        cout << res << "\n"; 
    }
}