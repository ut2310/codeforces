#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll a,b,c; cin >> a >> b >> c;
        if(c == a+ 1)
        {
            ll cnt = 0;
            ll depth = 1;
            ll res = 0;
            while(cnt + depth <= a)
            {
                cnt += depth;
                depth *= 2;
                res++;
            }   
            if(cnt < a)
            {
                res++;
                ll rem = cnt + depth - a;
                b -= rem;
            }
            //cout << res << " " << b << "\n";
            if (b > 0)
            {
                //ceil of b/(c + 1)
                res += (b + c - 1)/(c);
            }
            cout << res << "\n";
        }
        else
        {
            cout << "-1\n";
        }
        

    }
}