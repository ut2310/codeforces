using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
ll n, q;
ll bs(ll a)
{
    ll low = 1;
    ll high = n;
    while(low < high){
        ll mid = (low + high)/2;
        if(mid * (2*n - mid + 1) >= 2 * a){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> ps(n + 1);
    vector<ll> ps2(n + 1);
    vector<ll> ps3(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
        ps2[i] = ps2[i - 1] + ps[i];
    }
    ps3[1] = ps2[n];
    for(int i = 2; i <= n; i++){
        ps3[i] = ps2[n] - ps2[i - 1] - (ps[i - 1] * (n - i + 1)) + ps3[i - 1];
    }
    cin >> q;
    while(q-->0){
        ll l, r; cin >> l >> r;
        ll a1 = bs(l);
        ll a2 = l - ((a1 - 1) * (2*n - (a1 - 1) + 1))/2 + (a1 - 1);
        ll b1 = bs(r);
        ll b2 = r - ((b1 - 1) * (2*n - (b1 - 1) + 1))/2 + (b1 - 1);
        //cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
        ll res = 0;
        if(a1 == b1){
            res = ps2[b2] - ps2[a2 - 1] - (ps[a1 - 1] * (r - l + 1)); 
        }
        else{
            res += ps2[n] - ps2[a2 - 1] - (ps[a1 - 1] * (n - a2 + 1));
            res += ps2[b2] -  ps2[b1 - 1]  - (ps[b1 - 1] * (b2 - b1 + 1));
            //everything between a1 + 1 and b1 - 1 is included;
            //cout << ps3[b1 - 1] - ps3[a1] << "\n";
            res += ps3[b1 - 1] - ps3[a1];
        }       
        cout << res << "\n";
    }
}