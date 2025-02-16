using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
map<ll, vector<ll>> mp;
ll bfs(ll start, pair<ll, ll> finish)
{
    queue<ll> track; track.push(start);
    map<ll, ll> dist;
    dist[start] = 0;
    while(track.size() > 0){
        ll curr = track.front();
        //if(start == 0) cout << curr << " " << dist[curr] << " " << "\n";
        track.pop();
        for(auto j: mp[curr]){
            if(dist.count(j) > 0){
                continue;
            }
            dist[j] = dist[curr] + 1;
            track.push(j);
        }   
    }
    // if(start == 0){
    //     for(auto j: dist){
    //         cout << j.ff << " " << j.ss << "\n";
    //     }
    //     cout << finish.ff << " " << finish.ss << "\n";
    // }
    ll res = 1e9;
    if(dist.count(finish.ff) > 0){
        res = min(res, dist[finish.ff]);
    }
    if(dist.count(finish.ss) > 0){
        res = min(res, dist[finish.ss]);
    }
    return res;
}
int main()
{
    freopen("lasers.in","r",stdin);    
    freopen("lasers.out", "w", stdout);
    ll n, sx, sy, ex, ey;
    cin >> n >> sx >> sy >> ex >> ey;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        mp[2 * x].push_back(2 * y + 1);
        mp[2 * y + 1].push_back(2 * x);
    }
    // for(auto j: mp){
    //     cout << j.first << " ";
    //     for(auto j1: j.second){
    //         cout << j1 << " ";
    //     }
    //     cout << "\n";
    // }
    ll res1 = 1e9;
    //cout << sx << " " << ex << " " << ey << "\n";
    res1 = min(res1, bfs(2 * sx, {2 * ex, 2 *ey + 1}));
    res1 = min(res1, bfs(2 * sy + 1, {2*ex, 2 * ey + 1}));
    if(res1 == 1e9){
        cout << "-1\n";
    }
    else{
        cout << res1 << "\n";
    }
}

