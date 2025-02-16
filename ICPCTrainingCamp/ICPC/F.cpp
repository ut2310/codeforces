using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

ll power(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;
    ll p = power(x, y /2, M) % M;
    p = (p * p) % M;
    return (y % 2 == 0) ? p : (x * p) % M;
}
int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        ll index = power(7, power(7, power(7, n, 1.6 * 1e9), 4 * 1e9), 1.5 * 1e10);

        //now i just to get the fibonacci number with index at like 1e10

    }   
    //ll t; cin >> t;
    //get it mod 7^7^7^n
    //take 
    ll curr1 = 0; ll curr2 = 1; ll M = 1000000000;
    ll n = 1.5*1e10 + 5;
    for(int i = 1; i <= n; i++){
        ll temp = curr2;
        curr2 += curr1;
        curr2 %= M;
        curr1 = temp;
        curr1 %= M;
        //curr1 is the ith fibanochi number
        if(curr1 == 0 && curr2 == 1){
            cout << i << "\n";
            break;
        }
    }
}