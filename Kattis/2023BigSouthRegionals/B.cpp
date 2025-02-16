using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 5005
ll n;
ll ances[MAXN][MAXN];
bool dp[MAXN][MAXN];
ll dist[MAXN][MAXN];
ll parent[MAXN]; 
vector<ll> adj[MAXN];
void dfs1(ll p, ll v, ll root, ll depth){
    if(root == 0){
        parent[v] = p;
    }
    dist[root][v] = depth;
    for(auto u: adj[v]){
        if(u != p){
            dfs1(v, u, root, depth + 1);
        }
    }
}
void dfs2(ll p, ll v, ll root, ll stop){
    if(dp[root][v] == 0 && stop != -1){
        if(dp[stop][v] == 1){
            dp[root][v] = 1;
        }
    }
    for(auto u: adj[v]){
        if(u != p){
            if(dp[root][v] == 1){
                dfs2(v, u, root, u);
            }
            else{
                dfs2(v, u, root, stop);
            }
        }
    }
}
bool check(char a, char b){
    if(a == '(' && b == ')'){
        return true;
    }
    if(a == '{' && b == '}'){
        return true;
    }
    if(a == '[' && b == ']'){
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    for(int i = 0; i < n; i++){
        dfs1(i, i, i, 0);

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            ances[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        ances[i][i] = 1;
        ll temp = i;
        while(temp != 0){
            ll og = temp;
            temp = parent[temp];
            ances[temp][i] = og;
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << i << " " << j << " " << ances[i][j] << " " << dist[i][j] << "\n";
    //     }
    // }
    vector<pair<ll, pair<ll, ll>>> order;
    vector<ll> first(n);
    for(int i = 0; i < n; i++){
        first[i] = -1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dist[i][j] % 2 != 0){
                if(dist[i][j] == 1){
                    if(check(s[i], s[j])){
                        dp[i][j] = 1;
                        first[i] = j;
                        cout << i << " " << j << "\n";
                    }
                    if(check(s[j], s[i])){
                        dp[j][i] = 1;
                        first[j] = i;
                        cout << j << " " << i << "\n";
                    }
                    
                }
                else{
                    order.push_back({dist[i][j], {i, j}});
                }
            }
        }
    }
    
    sort(order.begin(), order.end());
    for(int n = 0; n < order.size(); n++){
        ll n1 = order[n].second.first;
        ll n2 = order[n].second.second;
        //cout << n1 << " " << n2 << "\n";
        if((!check(s[n1], s[n2])) && (!check(s[n2], s[n1]))){
            continue;
        }
        if(check(s[n2], s[n1])){
            swap(n1, n2);
        }
        if(ances[n1][n2] != -1){
            ll next1 = ances[n1][n2];
            ll next2 = parent[n2];
            if(dp[next1][next2]){
                dp[n1][n2] = 1;
            }
        }
        else if(ances[n2][n1] != -1){
            ll next1 = ances[n2][n1];
            ll next2 = parent[n1];
            if(dp[next2][next1]){
                dp[n1][n2] = 1;
            }
        }
        else{
            ll next1 = parent[n1];
            ll next2 = parent[n2];
            if(dp[next1][next2]){
                dp[n1][n2] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j]){
                cout << i << " " << j << "\n";
            }
        }
    }
    for(int i = 0; i < n; i++){
        dfs2(i, i, i, -1);
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j]){
                cout << i << " " << j << "hi\n";
                res++;
            }
        }
    }
    cout << res << "\n";

}