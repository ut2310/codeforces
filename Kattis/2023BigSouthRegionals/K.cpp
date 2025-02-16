using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1005
#define ALPHABETSIZE 

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k, a, b; cin >> n >> k >> a >> b;
        // n/(n + 1) >= a/b
        if(n * b < (n + 1) * a){
            cout << "-1\n";
            continue;
        }
        //take all n serious runners when is n/(n + x) < a/b --> nb < a(n + x) --> n(b - a) < ax --> x > n(b - a)/a when this happens
        //x > n(b - a)/a where n is the number of serious rnners

        ll n1 = n; ll res = 0;
        while(n1 < (n + k)){
            ll r = (n1 * (b - a))/a; //find minimum x such that 
            ll C = a - ((n1*(b - a) + a) % a);
            ll X = (C + b - a - 1)/(b - a);
            ll x = (X + r - 1)/r;
            ll other_x = (n + k - n1 + r - 1)/r;
            n1 += min(x, other_x) * r;
            res += min(x, other_x);
            //cout << x << "\n";
        }
        cout << res << "\n";
    }
    
}