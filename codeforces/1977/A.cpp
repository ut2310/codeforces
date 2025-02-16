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
        ll m, n; cin >> n >> m;
        if(m > n) cout << "No\n";
        else if((m - n) % 2 != 0) cout << "No\n";
        else cout << "Yes\n";
    }
}