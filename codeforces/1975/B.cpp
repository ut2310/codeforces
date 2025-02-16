using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
 
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
        sort(a.begin(), a.end());
        ll curr1 = a[0];
        ll curr2 = -1;
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            if(a[i] % curr1 != 0 && curr2 == -1)
            {
                curr2 = a[i];
            }
            else if(a[i] % curr1 != 0 && a[i] % curr2 != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}    