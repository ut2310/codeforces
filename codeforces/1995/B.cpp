using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(n);
        map<ll, ll> freq;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
            freq[a[i]] += b[i];
        }
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            ll freq1 = freq[a[i]];
            ll freq2 = 0;
            if(freq.count(a[i] + 1) > 0)
            {
                freq2 += freq[a[i] + 1];
            }
            if(freq1 * a[i] + freq2 * (a[i] + 1) > m)
            {
                ll curr = (m/a[i]) * a[i];
                if(m/a[i] <= freq1)
                {
                    ll temp = m - curr;
                    curr += min(temp, min(m/a[i], freq2));
                }
                else
                {
                    curr = freq1 * a[i];
                    ll used = (m - curr)/(a[i] + 1);
                    curr += used * (a[i] + 1);
                    ll temp = m - curr;
                    curr += min(temp, min(freq1, freq2 - used));
                }

                res = max(res, curr);
            }   
            else
            {
                //cout << freq1 << " " << a[i] << " " << freq2 << "\n";
                res = max(res, freq1 * a[i] + freq2 * (a[i] + 1));
            }
        }
        cout << res << "\n";
    }
}