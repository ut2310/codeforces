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
        ll res = 1;
        for(int i = 0; i <= 25; i++)
        {
            vector<ll> temp;
            bool flag = false;
            for(int j =0; j < n; j++)
            {
                if(a[j] & (1 << i))
                {
                    temp.push_back(1);
                    flag = true;
                }
                else
                {
                    temp.push_back(0);
                }
            }
            if(flag)
            {
                ll track = 0;
                ll most0 = 0;
                for(int j = 0; j < n; j++)
                {
                    if(temp[j] == 0)
                    {
                        track++;
                    }
                    else
                    {
                        most0 = max(most0, track);
                        track =0;
                    }
                }
                most0 = max(most0, track);
                //cout << most0 << "\n";
                res = max(res, most0 + 1);
            }
            else
            {
                res = max(res, 1LL);
            }

        }
        cout << res << "\n";
    }
}