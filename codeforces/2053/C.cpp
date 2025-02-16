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
        ll n, k; cin >> n >> k;
        ll n1 = n;
        ll res = 0;
        ll cnt = 1;
        while(n1 >= k){
            if(n1 % 2 == 1){
                //length is n1 we need n - n1 + 1 to n median
                ll m2 = (n + n - n1 + 1)/2;
                res += cnt * ((n1 + 1)/2  + m2)/2;
            }
            n1 = n1/2;
            cnt *= 2;
        }
        cout << res << "\n";
    }
}