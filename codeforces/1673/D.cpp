#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005 
int main()
{
    std::ios::sync_with_stdio(false);
    ll t; cin >> t;
    while(t-->0)
    {
        ll b, q, y; ll c, r, z; 
        cin >> b >> q >> y;
        cin >> c >> r >> z; //r has to be divisible by q
        bool flag = true;
        if(r % q != 0) flag = false;
        if(b > c || b + q * (y - 1) < c + z * (r - 1)) flag = false;
        if(flag)
        {
            
        }

    }
}