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
        vector<ll> a(n);
        set<ll> pos;
        for(int i = 1; i <= 10000; i+=2){
            pos.insert(i * i);
        }
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll track = 0;
        ll res = 0;
        for(int i = 0; i < n; i++){
            track += a[i];
            if(pos.count(track) > 0){
                res++;
            }
        }
        cout << res << "\n";
    }
}