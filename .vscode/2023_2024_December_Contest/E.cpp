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
#define MAXN 200005
#define ll long long
int t, n;
vector<ll> binary(ll x)
{
    vector<ll> res;
    while(x > 0)
    {
        res.push_back(x % 2);
        x = x/2;
    }
    vector<ll> res2;
    for(int i = 0; i < 30 - res.size(); i++)
    {
        res2.push_back(0);
    }
    for(int i = res.size() - 1; i >= 0; i--)
    {
        res2.push_back(res[i]);
    }
    return res2;
}
ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        ll q = A / M;
        ll t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    map<ll, ll> track;
    while(t-->0)
    {
        cin >> n;
        vector<ll> input;
        set<ll> c;
        ll M = 998244353;
        ll track2 = 0;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        for(int i = 0; i < n; i++)
        {
            ll temp = input[i];
            vector<ll> x = binary(temp);
            track[1]++;
            ll prev = 1;
            for(int j = 0; j < x.size(); j++)
            {
                if(x[j] == 0)
                {
                    prev *= 2;
                    track[prev]++;
                }
                else
                {
                    track2++;
                    prev *= 2;
                    prev++;
                    track[prev]++;
                }
                c.insert(prev);
            }
        }
        ll res = 0;
        vector<ll> cc;
        for(auto i: c)
        {
            cc.push_back(i);
            //cout << i << " ";
        }
        //cout << "\n";
        for(int i = 0; i < cc.size() - 1; i++)
        {
            if(cc[i + 1] == cc[i] + 1 && cc[i] % 2 == 0)
            {
                vector<ll> chi = binary(cc[i]);
                ll b = 0;
                for(int i = 0; i < chi.size(); i++)
                {
                    if(chi[i] == 1)
                    {
                        b++;
                    }
                }
                ll bb = (track[cc[i]] * track[cc[i + 1]] * (2 * b - 1)) % M;
                res = (res + bb) % M;
                
            }
        }
        //cout << res << " " << track2 << " " << n << "\n";
        res = (res + track2 + n) % M;
        ll value = modInverse(n * n, M);
        ll final_res = (value * res) % M;
        cout << final_res << "\n";

    }
}