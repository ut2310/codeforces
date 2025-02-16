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
vector<pair<ll, ll>> adj[MAXN];
ll visited[MAXN], rank2[MAXN];
vector<ll> top_sort;
void dfs(int node) {
    visited[node] = 1;
	for (auto next : adj[node]) {
		if (visited[next.ss] == 0) {
			dfs(next.ss);
		}
	}
	top_sort.push_back(node);
}
int main()
{
    ll N, M; cin >> N >> M;
    for(int i = 0; i < M; i++){
        ll a, b, w; cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            dfs(i);
        }
        // for(int i = 0; i < top_sort.size(); i++){
        //     cout << top_sort[i] << " ";
        // }
        // cout << "\n";
    }
    
    vector<pair<ll, ll>> res(N + 1);
    res[top_sort[0]] = {0, 0};
    vector<pair<ll, ll>> sn(N + 1);
    vector<pair<ll, ll>> rank_size(N);
    sn[top_sort[0]] = {0, -1};
    for(int i = 1; i < N; i++){
        ll node = top_sort[i];
        ll longest = 0;
        ll update = 0;
        pair<ll, ll> curr = {0, -1};
        for (auto v: adj[node]){
            if(res[v.ss].ff + 1 > longest){
                longest = res[v.ss].ff + 1;
                update = v.ff + res[v.ss].ss;
                curr = {v.ff, v.ss};
            }
            else if(res[v.ss].ff + 1 == longest && curr.first == v.ff){
                //important node to consider, check whos better v.ss or curr.ss
                ll n1 = curr.ss; ll n2 = v.ss;
                bool flag = false;
                if(rank2[n2] < rank2[n1]){
                    flag = true;
                }
                //cout << node << " " << n1 << " " << n2 << "hi\n";
                // bool flag = false;
                // while(sn[n1].second != -1){
                //     //cout << sn[n1].first << " " << sn[n1].second << "\n";
                //     //cout << sn[n2].ff << " " << sn[n2].ss << "\n";
                //     if(sn[n2].first < sn[n1].first){
                //         flag = true;
                //         break;
                //     }
                //     else if(sn[n2].first > sn[n1].first){
                //         break;
                //     }
                //     n1 = sn[n1].second;
                //     n2 = sn[n2].second;
                // }
                if(flag){
                    curr = {v.ff, v.ss};
                    update = v.ff + res[v.ss].ss;
                }
            }
        }
        res[node] = {longest, update};
        sn[node] = curr;
    }
    //cout << "\n";
    for(int i = 1; i <= N; i++){
        cout << res[i].first << " " << res[i].ss << "\n";
    }
}