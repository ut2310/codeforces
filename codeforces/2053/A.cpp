using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool flag = false;
        for(int i = 1; i < n; i++){
            if(2 * min(a[i - 1], a[i]) > max(a[i - 1], a[i])) flag = true;
        }
        if(flag){ cout << "YES\n";}
        else cout << "NO\n";
    }
}