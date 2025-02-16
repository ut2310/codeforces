using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> pref(n + 1); //prefix +
        vector<ll> suf(n + 1); //suffix -
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0){
                pref[i + 1] = pref[i] + a[i];
            }
            else{
                pref[i + 1] = pref[i];
            }
        }
        if(a[n - 1] < 0) suf[n] = abs(a[n - 1]);
        for(int i = n - 2; i >= 0; i--){
            if(a[i] < 0){
                suf[i + 1] = suf[i + 2] + abs(a[i]);
            }
            else{
                suf[i + 1] = suf[i + 2];
            }
        }
        ll res = 0;
        for(int i = 1; i <= n; i++){
            res = max(pref[i] + suf[i], res);
        }
        cout << res << "\n";
        
    }

}