using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
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
        ll l, r, G; cin >> l >> r >> G;
        ll start = (l + G - 1)/G;
        ll end = r/G;
        if(end >= start){
            ll res1 = -1; 
            ll res2 = -1;
            bool flag = false;
            for(ll i = end - start; i >= 0; i--){
                for(ll j = start; j <= end - i; j++){
                    if(__gcd(i, j) == 1){
                        res1 = j;
                        res2 = j + i;
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag){
                cout << G * res1 << " " << G * res2 << "\n";
            }
            else{
                cout << "-1 -1\n";
            }
        }
        else{
            cout << "-1 -1\n";
        }
    }
}