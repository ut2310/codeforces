using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 22
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
        bool flag = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++){
            ll get = max(i - 0LL, n - i - 1LL);
            //cout << get << " " << a[i] << "\n";
            if(2 * get >= a[i]){
                flag = false;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}