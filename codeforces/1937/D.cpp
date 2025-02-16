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
        string s; cin >> s;
        vector<ll> toR;
        vector<ll> toL;
        toR.push_back(0);
        toL.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            if(s[i - 1] == '>')
            {
                toR.push_back(i);
            }
            else
            {
                toL.push_back(i);
            }
        }
        toL.push_back(n + 1);
        ll pr = 1;
        ll pl = 1;
        // for(auto j: toR)
        // {
        //     cout << j << " ";
        // }
        // cout << "\n";
        // for(auto j: toL)
        // {
        //     cout << j << " ";
        // }
        // cout << "\n";

        vector<ll> psL;
        vector<ll> psR;
        psL.push_back(0);
        psR.push_back(0);
        for(int i = 1; i < toR.size(); i++)
        {
            ll e = psR[psR.size() - 1];
            psR.push_back(e + toR[i]);
        }
        for(int i = 1; i < toL.size(); i++)
        {
            ll e = psL[psL.size() - 1];
            psL.push_back(e + toL[i]);
        }

        for(int i = 1; i <= n; i++)
        {
            //cout << "\n" <<  i << " " << toL[pl] << " " << toR[pr] << "\n";
            if(pl < toL.size())
            {
                if(toL[pl] == i)
                {
                    ll get = lower_bound(toR.begin(), toR.end(), i) - toR.begin() - 1;
                    //cout << get << "\n";
                    if((get + 1) > toL.size() - pl - 1)
                    {
                        ll res = (n + 1) - i;
                        ll size = psL.size() - 2 - (pl - 1);
                        ll repeats = (psL[psL.size() - 2] - psL[pl - 1]) - (psR[get] - psR[get - (size)]);
                        res += 2 * repeats;
                        cout << res << " ";
                    }
                    else
                    {
                        ll res = i;
                        ll repeats =  (psL[pl + get] - psL[pl]) - psR[get];
                        res += 2 * repeats;
                        cout << res << " ";
                    }
                    pl++;
                }
            }
            
            if(pr < toR.size())
            {
                if(toR[pr] == i)
                {
                    ll get = upper_bound(toL.begin(), toL.end(), i) - toL.begin();
                    if(toL.size() - get > pr) //goes to 0
                    {
                        ll res = i;
                        ll repeats = (psL[get - 1 + pr] - psL[get - 1]) - psR[pr];
                        res += 2 * repeats;
                        cout << res << " ";
                    }
                    else
                    {
                        ll res = (n + 1) - i;
                        ll size = psL.size() - 2 - (get - 1);
                        ll repeats = (psL[psL.size() - 2] - psL[get - 1]) - (psR[pr - 1] - psR[pr - 1 - size]);
                        res += 2 * repeats;
                        cout << res << " ";
                    }
                    pr++;
                }
            }
            
        }
        cout << "\n";
    }
}