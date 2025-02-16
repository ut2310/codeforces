using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll res = 1;
        set<ll> track; 
        track.insert(x);
        for(int i = 0; i < n; i++)
        {
            if(x % a[i] == 0 && track.count(a[i]) > 0)
            {
                //cout << i << "\n";
                res++;
                track.clear();
                track.insert(x);
                track.insert(x/a[i]);
            }
            else if(x % a[i] == 0)
            {
                //cout << i << "hello\n";
                for(auto j: track)
                {
                    if(j % a[i] == 0)
                    {
                        track.insert(j/a[i]);
                    }
                }
            }
            
        }
        cout << res << "\n";
    }
}