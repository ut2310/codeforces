#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
        bool flag = true;
        sort(a.begin(), a.end());
        if(a[0] == 1)
        {
            bool flag2 = true;
            for(int i = 1; i < n; i++)
            {
                if(a[i] - a[i - 1] > 1)
                {   
                    flag2 = false;
                }
            }
            if(flag2)
            {
                if(a[n - 1] % 2 == 0) flag = false;
            }
            else
            {
                ll incr = 0;
                for(int i = 1; i < n; i++)
                {
                    if(a[i] - a[i - 1] >= 1)
                    {   
                        incr++;
                        if(a[i] - a[i - 1] > 1)
                        {
                            if(incr % 2 == 1) flag = false;
                            else flag = true;
                            break;
                        }
                    }
                }
            }
        }
        if(flag) cout << "Alice\n";
        else cout << "Bob\n";
    }
}