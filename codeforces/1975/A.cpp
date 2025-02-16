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
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            bool temp = true;
            for(int j = i + 1; j < n; j++)
            {   
                if(a[j] < a[j - 1])
                {
                    temp = false;
                }
            }
            for(int j = 0; j < i; j++)
            {
                if(j == 0) 
                {
                    if(a[n - 1] > a[0]) temp = false;
                }
                else
                {
                    if(a[j] < a[j - 1]) temp = false;
                }
            }
            //cout << temp << " " << i << "\n";
            if(temp) flag = true;
        }   
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}    