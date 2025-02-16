#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(n);
        vector<ll> b(m);
        map<ll, ll> pos;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int j = 0; j < m; j++)
        {
            cin >> b[j];
            pos[b[j]]++;
        }
        map<ll, ll> track;
        ll matches = 0;
        for(int i = 0; i < m; i++)
        {
            if(pos.count(a[i]) > 0)
            {
                track[a[i]]++;
                if(track[a[i]] <= pos[a[i]]) matches++;
            }
        }
        ll res = 0;
        if(matches  >= k) res++;
        //cout << res << "\n";
        for(int i = 1; i <= n - m; i++)
        {
            if(track.count(a[i - 1]) > 0)
            {
                track[a[i - 1]]--;
                if(track[a[i - 1]] < pos[a[i - 1]])
                {
                    matches--;
                }
            }
            //cout << i << " " << matches << "\n";
            if(pos.count(a[i + m - 1]) > 0)
            {
                track[a[i + m - 1]]++;
                if(track[a[i + m - 1]] <= pos[a[i + m - 1]]) matches++;
            }
            //cout << i << " " << matches << "\n";
            if(matches >= k)
            {
                res++;
                //cout << i << "\n";
            } 

        }
        cout << res << "\n";
    }   
}