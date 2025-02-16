#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        string s; cin >> s;
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            ll last = -1;
            ll prev = 0;
            for(int j = i; j < n; j++)
            {
                if(last == -1)
                {
                    if(s[j] == '1')
                    {
                        last = j;
                        res++;
                        prev = 1;
                    }
                    last = j;
                    res++;
                }
                else if(s[j] == '')
            }
        }
    }
}