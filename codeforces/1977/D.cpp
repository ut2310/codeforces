using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m; cin >> n >> m;
        vector<ll> a(m);
        vector<vector<ll>> store (n, vector<ll>(m));
        for(int i = 0; i < n; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < m ; j++)
            {
                if(s[j] == '1')
                {
                    a[j]++;
                    store[i][j] = -1;
                }
                else
                {
                    a[j]--;
                    store[i][j] = 1;
                }
            }
        }
        ll odd = 0; ll even = 0;
        for(int i = 0; i < m; i++)
        {
            if(a[i] % 2 == 0) even++;
            if(a[i] % 2 == 1) odd++;
        }
        ll res = max(odd, even);
        
    }
}