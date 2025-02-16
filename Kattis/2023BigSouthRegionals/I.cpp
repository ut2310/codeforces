using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1005
#define ALPHABETSIZE 
ll n, m, s, p, q, pages;
set<ll> mp1[MAXN];
set<ll> mp2[MAXN];
ll get_min_ops(set<ll> ps, set<ll> ns, ll page_size)
{
    // three cases: individually do it, select all, deselect all
    ll overlap = 0;
    for(auto i: ps){
        if(ns.count(i) > 0){
            overlap++;
        }
    }
    ll res1 = ps.size() - overlap + ns.size() - overlap;
    ll res2 = 1 + ns.size();//deselect all
    ll res3 = 1 + page_size - ns.size(); // select all
    return min(res1, min(res2, res3));
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> m >> s >> p >> q;
    vector<ll> ps(p);
    vector<ll> ns(q);
    for(int i = 0; i < p; i++){
        cin >> ps[i];
    }
    for(int i = 0; i < q; i++){
        cin >> ns[i];
    }
    pages = (n + m - 1)/m;
    sort(ps.begin(), ps.end());
    sort(ns.begin(), ns.end());
    vector<ll> ops(pages + 1);
    for(int i = 0; i < p; i++){
        ll get = ((ps[i] - 1)/m) + 1;
        mp1[get].insert(ps[i]);
    }
    for(int i = 0; i < q; i++){
        ll get = ((ns[i] - 1)/m) + 1;
        mp2[get].insert(ns[i]);
    }
    ll res = 0;
    for(int i = 1; i <= pages; i++){
        ll page_size = m; 
        if(i == pages){
            page_size = (n + m) % m;
            if(page_size == 0){
                page_size = m;
            }
        }
        // cout << i << "\n";
        // for(auto j: mp1[i]){
        //     cout << j << " ";
        // }
        // cout << "\n";
        // for(auto j: mp2[i]){
        //     cout << j << " ";
        // }
        // cout << "\n";
        ops[i] = get_min_ops(mp1[i], mp2[i], page_size);
        res += ops[i];
        //cout << ops[i] << " ";
    }
    //cout << "\n";
    ll first = 1;
    ll end = pages;
    for(int i = 1; i <= pages; i++){
        if(ops[i] != 0){
            first = i;
            break;
        }
    }
    if(ops[first] == 0){
        first = pages;
    }
    
    for(int i = pages; i >= 1; i--){
        if(ops[i] !=0){
            end = i;
            break;
        }
    }
    if(ops[end] == 0){
        end = 1;
    }
    if(first > end || res == 0){
        cout << "0\n";
    }
    else{
        if(s <= first){
            res += end - s;
        }
        else if(s >= end){
            res += s - first;
        }
        else{
            res += min(end - s, s - first) + end - first;
        }
        cout << res << "\n";
    }

}