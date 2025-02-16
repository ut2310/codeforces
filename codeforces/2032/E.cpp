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
        vector<ll> a(n);
        vector<ll> d(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        d[0] = a[n - 1] - a[n];
        for(int i = 1; i < n; i++){
            d[i] = a[i - 1] - a[i];
        }
        vector<ll> v(n);
        
    }
}