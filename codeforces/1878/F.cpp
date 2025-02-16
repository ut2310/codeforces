using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define MAXN 1000005
ll t, n, q;
bool prime[MAXN];
unordered_set<ll> primesquare;
ll a[MAXN];
void SieveOfEratosthenes(int n)
{
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int j = 0;
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            // Storing primes in an array
            a[j] = p;
 
            // Update value in primesquare[p*p],
            // if p is prime.
            primesquare.insert(p * p);
            j++;
        }
    }
}
bool check_prime(ll n)
{
    bool flag = true;
    for(ll i = 0; i < 660000; i++)
    {
        if(n == a[i])
        {
            return true;
        }
        if(n % a[i] == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
map<ll, ll> primefactorize(ll n)
{
    map<ll, ll> store;
    if(n == 1)
    {
        return store;
    }
    for (ll i = 0; i <= 10000; i++) {
        ll cnt = 0;
        while (n % a[i] == 0) 
        {
            n = n / a[i];
            cnt = cnt + 1; 
        }
        if(cnt > 0) store[a[i]] = cnt;
        if(prime[n])
        {
            store[n]++;
            n = 1;
        }
        if(n == 1) break;
    }
    if(n != 1) store[n] += 1;
    n = 1;
    return store;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    SieveOfEratosthenes(1000003);
    while(t-->0)
    {
        cin >> n >> q;
        map<ll, ll> og = primefactorize(n);
        map<ll, ll> curr = og;
        while(q-->0)
        {
            ll a, b; cin >> a;
            if(a == 1)
            {
                cin >> b;
                map<ll, ll> bpf = primefactorize(b);
                for(auto j: bpf)
                {
                    curr[j.first] += j.second;
                }
                ll divisors = 1;
                for(auto j: curr)
                {
                    divisors *= (j.second + 1);
                }
                map<ll, ll> pfdivisors = primefactorize(divisors);
                bool flag = true;
                for(auto j: pfdivisors)
                {
                    ll compare = curr[j.first];
                    if(compare < j.second) flag = false;
                }
                if(flag)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else
            {
                curr = og;
            }
        }
        cout << "\n";
    }
 
}