using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
ll N;
bool check(ll mid, vector<ll> &a,  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] < mid)
        {
            while(pq.size() > 0)
            {
                auto curr = pq.top();
                if(i <= curr.second && i >= curr.first)
                {

                }
            }
        }
    }
}
int main()
{
    cin >> N;
    vector<ll> a(N);
    vector<ll> D(N);
    ll l = 0;
    ll r = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    for(int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>,ll>>, greater<pair<pair<ll, ll>, ll>>> pq;
    for(ll i = 0; i < N; i++)
    {
        pq.push(make_pair(make_pair(min(i + D[i], N - 1), max(0LL, i - D[i])), i));
    }
    while(l < r)
    {
        ll mid = (l + r)/2;
        if(check(mid, a, pq))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

}