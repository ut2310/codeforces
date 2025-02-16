using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
ll x, y, z, k;
ll damage(ll a, ll b)
{
    ll c = min(a/k, b);
    return k * c * (c + 1)/2 + a*(b - c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        cin >> x >> y >> z >> k;
        ll res = 1e18;
        for(ll a = 1; a * a <= 2*z; a++){ //fixing a
            ll low = 0; ll high = z;
            while(low < high){
                ll b = (low + high)/2;
                if(damage(a, b) < z){
                    low = b + 1;
                }
                else{
                    high = b;
                }
            }
            //cout << a << " " << low << "\n";
            if(damage(a, low) >= z) res = min(res, x * a + y * low);
        }
        for(ll b = 1; b * b <= 2 * z; b++){
            ll low = 0; ll high = z;
            while(low < high){
                ll a = (low + high)/2;
                if(damage(a, b) < z){
                    low = a + 1;
                }
                else{
                    high = a;
                }
            }
            if(damage(low, b) >= z) res = min(res, x * low + y * b);
            //cout << low << " " << b << " " << res << "\n";

        }
        cout << res << "\n";
    }

}