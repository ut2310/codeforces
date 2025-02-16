using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n + 1);
        vector<ll> b(n + 1);
        vector<ll> bs(n + 1); //best
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        vector<vector<pair<ll, ll>>> neighbors(n + 1);
        for(int i = 1; i <= n; i++){
            neighbors[i].push_back(make_pair(i - 1, 0));
            neighbors[i].push_back(make_pair(b[i], a[i]));
        }
        vector<ll> ps(n + 1);
        for(int i = 1; i <= n; i++){
            ps[i] = ps[i - 1] + a[i];
        }
        using T = pair<long long, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<long long> dist(n + 1, LLONG_MAX);
        int start = 1;
        dist[start] = 0;  // The shortest path from a node to itself is 0
        pq.push({0, start});
        while (!pq.empty()) {
            const auto [cdist, node] = pq.top();
            pq.pop();
            if (cdist != dist[node]) { continue; }
            for (const pair<int, int> &i : neighbors[node]) {
                if (cdist + i.second < dist[i.first]) {
                    pq.push({dist[i.first] = cdist + i.second, i.first});
                }
            }
        }
        ll res = a[1];
        for(int i = 1; i <= n; i++){
            res = max(res, ps[i] - dist[i]);
        }
        cout << res << "\n";
    }
}