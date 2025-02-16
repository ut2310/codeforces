using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
ll M;
int main()
{
    M = 998244353;
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    ll product = 1;
    set<ll> primes;
    primes.insert(2);
    primes.insert(3);
    primes.insert(5);
    primes.insert(7);
    primes.insert(11);
    primes.insert(13);
    primes.insert(17);
    primes.insert(19);
    primes.insert(23);
    primes.insert(29);
    primes.insert(31);
    primes.insert(37);
    for(int i = 1; i <= min(n, 37LL); i++)
    {
        if(primes.count(i) > 0)
        {
            product *= i;
        }
        a[i] = m/product;
        a[i] %= M;
        if(a[i] < 0) a[i] += M;
        //cout << a[i] << " ";
    }
    //cout << "\n";
    ll total = 0;
    ll curr = 1;
    m %= M; if(m < 0) m += M;
    for(int i = 1; i <= n; i++)
    {
        
        curr *= m;
        curr %= M;  
        if(curr < 0) curr += M;
        //if(i == 3) cout << curr << " " << m << "\n";
        total += curr;
        total %= M;
        if(total < 0) total += M;
    }
    //cout << "\n";
    ll currproduct = 1;
    for(int i = 1; i <= min(n, 37LL); i++)
    {
        currproduct *= a[i];
        currproduct %= M;
        if(currproduct < 0) currproduct += M;
        total -= currproduct;
        cout << currproduct << " ";
        total %= M;
        if(total < 0) total += M;
    }
    cout << "\n";
    if(total < 0) total += M;
    cout << total << "\n";

}