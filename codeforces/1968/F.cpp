using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll calc(vector<ll> &a, ll e, bool flag)
{
    if(a.size() == 0) return -1;
    ll l = 0; ll r = a.size() - 1;
    while(l < r)
    {
        ll mid = (l + r)/2;
        if(a[mid] < e)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if(flag)
    {
        if(a.size() == 0) return -1;
        else if(a[r] < e) return a[r];
        else 
        {
            if(r == 0) return -1;
            else return a[r - 1];
        }
        
    }
    return a[r];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, q; cin >> n >> q;
        vector<ll> a(n + 1);
        vector<ll> pfx(n + 1);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i + 1];
        }
        for(int i = 1; i <= n; i++)
        {
            pfx[i] = pfx[i - 1] ^ a[i];
        }
        map<ll, vector<ll>> info;
        for(int i = 1; i <= n; i++)
        {
            info[pfx[i]].push_back(i);
        }
        while(q-->0)
        {
            ll l, r; cin >> l >> r;
            if((pfx[r] ^ pfx[l - 1]) == 0)
            {
                cout << "YES\n";
            }
            else
            {
                //cerr << pfx[r] << " " << pfx[l - 1] << "\n";
                bool flag = true;
                ll index1 = calc(info[pfx[r]], l, !flag); //gets first index thats greater than or equal to l
                ll index2 = calc(info[pfx[l - 1]], r, flag);//gets last index thats greater than or equal to r
                //cerr << index1 << " " << index2 << "\n";
                if(index1 < index2 && l <= index1 && index2 < r) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        cout << "\n";
    }
}