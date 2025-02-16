#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a1(n);
        vector<ll> a2(n);
        for(int i = 0; i < n; i++){
            cin >> a1[i];
        }
        for(int i = 0; i < n; i++){
            cin >> a2[i];
        }
        ll res = -1e18;
        for(int i = 0; i < n; i++){
            ll track = a1[i] + a2[i];
            for(int j = 0; j < n; j++){
                if(j != i){
                    track += max(a1[j], a2[j]);
                }
            }
            res = max(res, track);
        }
        cout << res << "\n";
    }
}