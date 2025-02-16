using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll cnt=0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] >= n - i)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
}