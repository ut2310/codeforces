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
        vector<ll> ps(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ps[i + 1] = ps[i] + a[i];
        }
        ll track = ps[n];
        for(int i = 0; i < n - 1; i++){
            if(a[i] > (track/ (n - i))){
                a[i + 1] += a[i] - (track/(n - i));
                a[i] = track/(n - i);
            }
            track -= a[i];
        }
        track = ps[n];
        for(int i = n - 1; i >= 1; i--){
            ll x = (track + i)/(i + 1);
            if(a[i] < x){
                a[i - 1] -= x - a[i];
                a[i] = x;
            }
            track -= a[i];
        }
        ll minc = 1e18;
        ll maxc = 0;
        for(int i = 0; i < n; i++){
            minc = min(minc, a[i]);
            maxc = max(maxc, a[i]);
        }
        cout << maxc - minc << "\n";
    }
}