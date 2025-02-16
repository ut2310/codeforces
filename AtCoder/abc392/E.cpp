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
ll parent[MAXN], rank_size[MAXN];

ll find_set(ll v) {
    if(parent[v] != v) parent[v] = find_set(parent[v]);
    return parent[v];  
}

bool union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_size[a] > rank_size[b])
            swap(a, b);
        parent[a] = b;
        rank_size[b] += rank_size[a];
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<pii> edges;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rank_size[i] = 1;
    }
    vector<ll> store_node(n + 1);
    for(int i = 1; i <= m; i++){
        ll a, b; cin >> a >> b;
        bool check = union_sets(a, b);
        if(check){
            edges.push_back({a, i});
        }
    }
    set<ll> pos;
    for(int i = 1; i <= n; i++){
        pos.insert(find_set(i));
    }
    vector<pair<pii, ll>> res;
    ll cnt = pos.size();
    while(cnt > 1){
        pii get2 = edges[edges.size() - 1];
        for(auto j: pos){
            if(find_set(j) != find_set(get2.ff)){
                res.push_back({{get2.ss, get2.ff}, find_set(j)});
                union_sets(j, get2.ff);
                pos.erase(j);
                break;
            }
        }
        edges.pop_back();
        cnt--;
    }
    cout << res.size() << "\n";
    for(auto j: res){
        cout << j.ff.ff << " " << j.ff.ss << " " << j.ss << "\n";
    }
}