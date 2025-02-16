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
        ll maxx = 0;
        ll maxy = 0;
        for(int i = 0; i < n; i++){
            ll x, y; cin >> x >> y;
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        }
        cout << 2 * (maxx + maxy) << "\n";
    }
}