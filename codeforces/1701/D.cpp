using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005

int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> b(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        vector<pair<pair<ll, ll>, ll>> track;
        for(int i = 1; i <= n; i++)
        {
            //cerr << "HELLO\n";
            if(b[i] == 0) track.push_back(make_pair(make_pair(i + 1, n), i));
            else
            {
                track.push_back(make_pair(make_pair(i/(b[i] + 1) + 1, i/b[i]), i));
            }
        }
        sort(track.begin(), track.end());

        ll p1 = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            while(p1 < n && track[p1].first.first <= i)
            {
                
                pq.push(make_pair(track[p1].first.second, track[p1].second));
                //cout << i << " " << track[p1].first.second << " " << track[p1].second << "s\n";
                p1++;
            }
            auto curr = pq.top();
            pq.pop();
            a[curr.second] = i;
        }
        for(int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}