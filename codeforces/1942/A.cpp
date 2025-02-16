#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        if(k == 1)
        {
            vector<ll> a(n);
            for(int i = 0; i < n; i++)
            {
                cout << i + 1 << " ";
            }

        }
        else if(k == n)
        {
            for(int i = 0; i < n; i++)
            {
                cout << 2 << " ";
            }
        }
        else
        {
            cout << "-1";
        }
        cout << "\n";
    }
}