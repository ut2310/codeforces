#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005 

int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for(int i= 0; i < n; i++)
    {
        k -= a[i] + 1;
        if(k >= 0) res++;
    }
    cout << res << "\n";

}