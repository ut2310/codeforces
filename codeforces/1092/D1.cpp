#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long
vector<ll> adj[MAXN];
ll visited[MAXN];
void dfs(ll u, ll assign)
{
    visited[u] = assign;
    for(auto v: adj[u]){
        if(visited[v] == 0){
            dfs(v, assign);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 != 0) a[i] = 1;
        else a[i] = 0;
    }
    vector<ll> check;
    for(int i = 0; i < n; i++){
        bool flag = false;
        if(check.size() > 0){
            if(a[i] == check[check.size() - 1]){
                check.pop_back();
                flag = true;
            }
        }
        if(!flag) check.push_back(a[i]);
    }
    if(check.size() <= 1) cout << "YES\n";
    else cout << "NO\n";
    
    // ll cmp = 1;
    // for(int i = 0; i < n; i++){
    //     if(visited[i] == 0){
    //         dfs(i, cmp);
    //         cmp++;
    //     }
    // }
    // vector<ll> imp;
    // //cout << cmp << "\n";
    // vector<ll> cnt(cmp);
    // for(int i = 0; i < n; i++){
    //     cnt[visited[i]]++;
    //     //cout << visited[i] << "\n";
    // }
    // for(int i = 1; i < cmp; i++){
    //     if(cnt[i] == 1){
    //         imp.push_back(i);
    //         //cout << i <<"hi\n";
    //     }
    // }
    // bool flag = true;  
    // for(int i = 1; i < imp.size(); i++){
    //     if((a[imp[i]] - a[imp[i - 1]]) % 2 != 0){
    //         flag = false;
    //     }
    // }
    // if(flag) cout << "YES\n";
    // else cout << "NO\n";
}