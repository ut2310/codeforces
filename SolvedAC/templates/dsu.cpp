using namespace std;
#include <bits/stdc++.h>
#define ll long long
vector<ll> parent, rank_size;

ll find_set(ll v) {
    if(parent[v] != v)
    {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];  
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_size[a] > rank_size[b])
            swap(a, b);
        parent[a] = b;
        rank_size[b] += rank_size[a];
    }
}