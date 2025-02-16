using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 105   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ll p, q, s; cin >> p >> q >> s;
    ll lcm_val = p * q/__gcd(p, q);
    if(lcm_val <= s){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
}