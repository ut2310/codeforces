using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
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
        vector<ll> b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        vector<ll> c(n);
        for(int i = 0; i < n; i++) c[i] = a[i] - b[i];
        ll cnt = 0; ll track = 0;  ll wor = 1e18;
        for(int i  = 0; i < n ; i++){
            if(c[i] < 0){
                cnt++;
                track = abs(c[i]);
            }
            else{
                wor = min(wor, c[i]);
            }
        }
        if(cnt == 0){
            cout << "YES\n";
        }
        else{
            if(cnt == 1 && track <= wor){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}