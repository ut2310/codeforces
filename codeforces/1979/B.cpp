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
        ll a, b; cin >> a >> b;
        ll res = 1;
        ll curr = 2;
        while((a - b) % curr == 0)
        {
            curr *= 2;
            res *= 2;
        }
        cout << res << "\n";
    }
}