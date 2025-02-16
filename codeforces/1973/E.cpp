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
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll first = -1;
        ll last = -1;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != i)
            {
                first = i;
                break;
            }
        }
        for(int i = n; i >= 1; i--)
        {
            if(a[i] != i)
            {
                last = i;
                break;
            }
        }
        if(first == -1 && last == -1)
        {
            ll res = (n) * (2 * n - 1) + (2 * n);
            cout << res << "\n";
        }
        else
        {
            //condition is r >= last + 1 && l <= first + n
            ll res = 0;
            //cout << first << " " << last << "\n";
            res += (2 * n - (first + n)) * (first + n); // case where r > first + n
            // case where first + n >= r >= last + 1
            res += ((first + n - 1 + last) * (first + n - last))/2;

            bool flag = true;
            for(int i = first; i <= (first + last)/2; i++)
            {
                if((i != a[first + last - i] || (first + last - i) != a[i]) && (i != a[i] || (first + last - i) != a[first + last - i]))
                {
                    flag = false;
                }
            }
            //cout << flag << "\n";
            if(flag) res++;
            cout << res << "\n";

        }
    }
}