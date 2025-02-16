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
        ll xc, yc, k; cin >> xc >> yc >> k;
        ll track = 0;
        ll track1 = 0;
        for(int i = 1; i < k - 1; i++)
        {
            cout << i << " " << i << "\n";
            track += i;
        }
        if(k == 1)
        {
            cout << xc << " " << yc << "\n";
            continue;
        }
        ll rem1 = k * xc - track;
        ll rem2 = k * yc - track;
        cout << 10000000 << " " << 10000000 << "\n";
        cout << rem1 - 10000000 << " " << rem2 - 10000000 << "\n";
    }
}