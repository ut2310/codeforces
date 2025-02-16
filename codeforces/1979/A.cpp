using namespace std;
#include <bits/stdc++.h>
#define ll long long

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
        vector<ll> b(n - 1);
        for(int i = 1; i < n; i++)
        {
            b[i - 1] = max(a[i], a[i - 1]);
        }
        sort(b.begin(), b.end());
        ll res = b[0] - 1;
        cout << res << "\n";
    }
}