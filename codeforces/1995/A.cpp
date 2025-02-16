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
        ll n, k; cin >> n >> k;
        ll count = 0;
        if(k == 0) cout << 0 << "\n";
        else
        {
            k -= n;
            count++;
            ll track = n - 1;
            while(k > 0)
            {
                k -= track;
                count++;
                if(k <= 0) 
                {
                    break;
                }
                k-= track;
                count++;
                if(k <= 0) break;
                track--;
            }
            cout << count << "\n";
        }
    }
}