#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 2005
pair<ll, ll> dp[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, l; cin >> n >> l;
        vector<pair<ll, ll>> input;
        for(int i = 0; i < n; i++)
        {
            ll a, b; cin >> a >> b;
            input.push_back(make_pair(b, a));
        }
        sort(input.begin(), input.end());
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            priority_queue<ll> pq;
            ll atotal = 0;
            for(int j = i; j < n; j++)
            {
                ll btotal = input[j].first - input[i].first;
                while(atotal + btotal > l && pq.size() > 0)
                {
                    ll top = pq.top();
                    atotal -= top;
                    pq.pop();
                }
                if(pq.size() == 0)
                {
                    if(atotal + btotal + input[j].second <= l)
                    {
                        pq.push(input[j].second);
                        atotal += input[j].second;
                    }
                }
                else
                {
                    if(atotal + btotal + input[j].second <= l)
                    {
                        pq.push(input[j].second);
                        atotal += input[j].second;
                    }
                    else
                    {
                        if(input[j].second <= pq.top())
                        {
                            ll top = pq.top();
                            atotal -= top;
                            atotal += input[j].second;
                            pq.pop();
                            pq.push(input[j].second);
                        }
                    }
                   
                }
                ll size = pq.size();
                //cout << btotal << " " << pq.size() << "\n";
                res = max(res, size);
               
            }
        }
        cout << res << "\n";
    }
}