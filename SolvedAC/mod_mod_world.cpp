using namespace std;
#include <bits/stdc++.h>
#include "atcoder/modint.hpp"
#define ll long long
#define MAXN 200005
ll recur(ll p, ll q, ll n)
{
    //cout << p << " " << q << " " << n << "\n";
    if(q == 1){
        return p * n * (n + 1)/2;
    }
    if(p > q){
        //cout << p << " " << q << "\n";
        return n * (n + 1)/2 * (p/q) + recur((p + q) % q, q, n);
    }
    if(n % q == 0){
        // n * pn/q
        double A = (n/q * p * (double) n)/2;
        double B = n + p*(n/q) + n/q;
        double I = A - B/2 + 1;
        //cout << A << " " << B << " " << I << "\n";
        return  I + n/q + p*(n/q) - 1;
    }
    else{
        ll total = ((p*n/q) + 1)*(n + 1);
        ll temp = recur(q, p, p * n/q);
        //cout << q << " " << p << " " << total << " " << temp << "\n";
        return total - temp + n/q - (n + p*n/q + 1);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll W; cin >> W;
    for(int i = 1; i <= W; i++){
        ll p, q, n; cin >> p >> q >> n;
        ll reduced_p = p/__gcd(p, q);
        ll reduced_q = q/__gcd(p, q);
        ll x = recur(reduced_p, reduced_q, n);
        //cout << x << "\n";
        ll res = p*n*(n + 1)/2 - q*x;
        cout << res << "\n";
    }
}