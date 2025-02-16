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
        ll m, x; cin >> m >> x;
        vector<ll> a(m);
        for(int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        priority_queue<ll> pq;
        ll value = 0;
        for(int i = 0; i < m; i++)
        {
            if(a[i] <= value)
            {
                pq.push(a[i]);
                value -= a[i];
            }
            else
            {
                if(pq.size() > 0)
                {
                    ll curr = pq.top();
                    if(a[i] < curr)
                    {
                        pq.pop();
                        pq.push(a[i]);
                        value -= a[i];
                        value += curr;
                    }
                }
            }
            value += x;
        }
        cout << pq.size() << "\n";
    }
}