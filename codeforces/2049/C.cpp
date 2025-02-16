using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> res(n + 1);
        if(n % 2 == 1){
            res[n] = 2;
            for(int i = 2; i <= n - 1; i++){
                res[i] = 1 - res[i - 1];
            }
        }
        else{
            for(int i = 2; i <= n; i++){
                res[i] = 1 - res[i - 1];
            }
        }
        if(res[x] == res[y]){
            if(n % 2 == 1 && (x == 1)){
                res[x] = 2;
                res[n] = 0;
            }
            else{
                res[x] = 2;
            }
        }
        for(int i = 1; i <= n; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}