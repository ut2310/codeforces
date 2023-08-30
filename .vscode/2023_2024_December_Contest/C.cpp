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
ll t, n;
vector<ll> binary(ll x)
{
    vector<ll> res;
    while(x > 0)
    {
        res.push_back(x % 2);
        x = x/2;
    }
    return res;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        ll x = 1;
        vector<ll> res;
        while(x <= n)
        {
            res.push_back(x);
            x*=2;
        }
        x/=2;

        vector<ll> help = binary(n);
        for(int i = help.size() - 2; i >= 0; i--)
        {
            if(help[i] == 1)
            {
                x += pow(2, i);
                res.push_back(x);
            }
        }

        cout << res.size() << "\n";
        for(int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}