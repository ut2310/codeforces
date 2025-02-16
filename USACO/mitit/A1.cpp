using namespace std;
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> adj[MAXN];
int main()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    set<ll> check;
    vector<ll> pos2(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        check.insert(a[i]);
    }
    for(auto j: check){
        pos2[a[j]] = j;
    }
    ll res = 0;
    vector<pair<ll, ll>> get;
    // 1 2 3 4 5
    // 
    multiset<ll> check2;
    for(auto j: check){
        check2.insert(a[j]);
    }
    for(auto j: check){
        if(a[j] == j){
            continue;
        }
        if(check2.count(j) > 0){
            res++;
            get.push_back({j, pos2[j]});
            swap(a[pos2[j]], a[j]);
            pos2[a[j]] = pos2[j];
            pos2[j] = j;
        }
        else{
            //get the new positions 
            check2.erase()
        }
        if(check2.count(j) == 0){
            res++;
            //cout << pos2[j] << " " << j << "\n";
            get.push_back({pos2[j], j});
            swap(a[pos2[j]], a[j]);
            pos2[a[j]] = pos2[j];
            pos2[j] = j;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    vector<ll> pos(n + 1);
    for(int i = 1; i <= n; i++){
        if(check.count(i) > 0){
            adj[i].push_back(a[i]);
            pos[a[i]] = i;
        }
        else res++;
    }
    
    // 1 2 2 3 (2 3 1) 1->2->3->1       pos[1]     3 4 5 1 2 1->3
    vector<ll> visited(n + 1);
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 0 || adj[i][0] == i) continue;
        if(visited[i] == 0){
            ll temp = i; ll cnt = 0; ll track = pos[temp];
            while(visited[temp] == 0){
                visited[temp] = 1;
                if(visited[adj[temp][0]] == 0){
                    get.push_back({temp, track});
                }
                cnt++;
                temp = adj[temp][0];
            }
            
            res += cnt - 1;
        }
    }
    cout << res << "\n";
    for(auto j: get){
        cout << 1 << " " << j.ff << " " << j.ss << "\n";
    }
    // for(auto j: check){
    //     cout << j << " ";
    // }
    // cout << "\n";
    for(int i = 1; i <= n; i++){
        if(check.count(i) == 0){
            cout << 2 << " " << i << " " << a[i] << "\n";
        }
    }

}