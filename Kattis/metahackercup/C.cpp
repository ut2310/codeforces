using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#include <cstdio>
ll M;
int main()
{
    freopen("substantial_losses_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    M = 998244353;
    for(int j = 1; j <= t; j++)
    {
        ll W, G, L; cin >> W >> G >> L;
        ll w = W - G;
        ll res = 0;
        if(L == 0){
            res = w;
        }
        else{
            w = w % M;
            ll mult = 2 * L + 1;
            mult %= M;
            res = w * mult;
        }
        res %= M;
        if(res < 0) res += M;
        cout << "Case #" << j << ": " << res << "\n";
    }
}