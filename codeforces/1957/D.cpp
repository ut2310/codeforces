#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 100005
vector<ll> store[31];
ll prefix0[31][MAXN];
ll suffix0[31][MAXN];
ll get(ll num)
{
    for(int i = 30; i >= 0; i--)
    {
        if(num & (1 << i))
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i <= 30; i++)
        {
            store[i].push_back(0);
            long long track = 0;
            for(int j = 0; j < n; j++)
            {
                if(a[j] & (1 << i))
                {
                    store[i].push_back(1 - track);
                    track = 1 - track;
                }
                else
                {
                    store[i].push_back(track);
                }
            }
        }
        // for(int i = 0; i <= 2; i++)
        // {
        //     for(auto j: store[i])
        //     {
        //         cerr << j << " ";
        //     }
        //     cerr << "\n";
        // }
        for(int i = 0; i <= 30; i++)
        {
            ll cnt0 = 1;
            prefix0[i][1] = 1;
            for(int j = 2; j <= n; j++)
            {
                if(store[i][j - 1] == 0)
                {
                    prefix0[i][j] = prefix0[i][j - 1] + 1;
                }
                else
                {
                    prefix0[i][j] = prefix0[i][j - 1];
                }
            }

            // for(int j1 = 0; j1 <= 2; j1++)
            // {
            //     cerr << prefix0[i][j1] << " ";
            // }
            // cerr << "\n";
            if(store[i][n] == 0)
            {
                suffix0[i][n] = 1;
            }
            for(int j = n - 1; j>= 0; j--)
            {
                if(store[i][j] == 0)
                {
                    suffix0[i][j] = suffix0[i][j + 1] + 1;
                }
                else
                {
                    suffix0[i][j] = suffix0[i][j + 1];
                }
            }   
        }
        
        ll res = 0;
        for(int i = 0; i < n; i++)
        {

            ll bit = get(a[i]);
            res += prefix0[bit][i + 1] * suffix0[bit][i + 1];
            res += ((i + 1) - prefix0[bit][i + 1]) * ((n - i) - suffix0[bit][i + 1]);
        }
        cout << res << "\n";
        for(int i = 0; i <= 30; i++)
        {
            store[i].clear();
            for(int j = 0; j <= n; j++)
            {
                prefix0[i][j] = 0;
                suffix0[i][j] = 0;
            }
        }

    }
}