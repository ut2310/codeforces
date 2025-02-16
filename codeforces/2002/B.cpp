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
        vector<ll> a(n); vector<ll> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) flag = false;
        }
        bool flag2 = true;
        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[n - 1 - i])
            {
                flag2 = false;
            }
        }
        if(flag || flag2) cout << "Bob\n";
        else cout << "Alice\n";
    }
}