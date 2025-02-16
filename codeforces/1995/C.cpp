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
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> res(n);
        ll final_res = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[i] == 1 && a[i - 1] != 1)
            {
                final_res = -1;
                break;
            }
            else if(a[i - 1] == 1)
            {
                res[i] = 0;
            }
            else if(a[i] == a[i - 1])
            {
                res[i] = res[i - 1];
            }
            else if(a[i] > a[i - 1])
            {
                ll count = 0;
                ll temp1 = a[i];
                ll temp2 = a[i - 1];
                while(temp1 >= temp2)
                {
                    temp2 *= temp2;
                    count++;
                }
                count--;
                res[i] = max(0LL, res[i - 1] - count);
            }
            else if(a[i] < a[i - 1])
            {
                ll count = 0;
                ll temp1 = a[i];
                ll temp2 = a[i - 1];
                while(temp1 < temp2)
                {
                    temp1 *= temp1;
                    count++;
                }
                res[i] = res[i - 1] + count;
            }
        }
        if(final_res == -1) cout << final_res << "\n";
        else
        {
            for(int i = 0; i < n; i++)
            {
                final_res += res[i];
            }
            cout << final_res << "\n";
        }
    }
}