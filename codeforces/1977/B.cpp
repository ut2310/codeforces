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
        ll x; cin >> x;
        vector<ll> a;
        for(int i = 0; i <= 30; i++)
        {
            if(x & (1 << i))
            {
                a.push_back(1);
            }
            else
            {
                a.push_back(0);
            }
        }
        bool flag = false;
        ll start = -1;
        for(int i = 1; i <= 30; i++)
        {
            //cout << a[i] << " ";
            if(a[i] != 0 && a[i - 1] != 0 && !flag)
            {
                flag = true;
                start = i - 1;
            }
            else if(a[i] == 0 && flag)
            {
                a[start] = -1;
                a[i] = 1;
                for(int j = start + 1; j < i; j++)
                {
                    a[j] = 0;
                }
                flag = false;
            }
        }
        if(flag)
        {
            a[start] = -1;
            for(int j = start + 1; j < a.size(); j++)
            {
                a[j] = 0;
            }
            a.push_back(1);
            flag = false;
        }
        cout << a.size() << "\n";
        for(int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
    }
}