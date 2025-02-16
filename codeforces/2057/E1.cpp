using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<pair<ll, ll>> adj[MAXN];
ll store[MAXN][MAXN][MAXN], n, m, q;
void bfs(ll thresh, ll index)
{
    deque<ll> queue;
    vector<ll> visited(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            store[index][i][j] = 1e9;
        }
        queue.clear();
        queue.push_front(i);
        store[index][i][i] = 0;
        while(queue.size() > 0){
            ll curr = queue.front();
            queue.pop_front();
            for(auto j: adj[curr]){
                ll w = (j.ss > thresh)? 1:0;
                if(store[index][i][curr] + w < store[index][i][j.ff]){
                    store[index][i][j.ff] = store[index][i][curr] + w;
                    if(w == 1){
                        queue.push_back(j.ff);
                    }
                    else{
                        queue.push_front(j.ff);
                    }
                }
            }
        }       
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        cin >> n >> m >> q;
        vector<ll> weights;
        for(int i = 0; i < m; i++){
            ll v, u, w; cin >> v >> u >> w;
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
            weights.push_back(w);
        }
        //cout << adj[3].size() <<"chicken2\n";
        sort(weights.begin(), weights.end());
        for(int i = 0; i < weights.size(); i++){
            bfs(weights[i], i);
            //cout << "hi2\n";
        }
        // for(int i = 0; i < weights.size(); i++){
        //     for(int a = 1; a <= n; a++){
        //         for(int b = 1; b <= n; b++){
        //             cout << weights[i] << " " << a << " " << b << " " << store[i][a][b] << "\n";
                    
        //         }
        //     }
        // }
        for(int i = 0; i < q; i++){
            ll a, b, k; cin >> a >> b >> k;
            ll low = 0; ll high = weights.size() - 1;
            while(low < high){
                ll mid = (low + high)/2;
                //if the shortest path is >= k its cooked, we know that the weight is bigger
                if(store[mid][a][b] >= k){
                    low = mid + 1;
                }   
                else{
                    high = mid;
                }
            }
            cout << weights[low] << " ";
        }
        cout << "\n";
        for(int i = 0; i <= n; i++){
            adj[i].clear();
        }

    }
}