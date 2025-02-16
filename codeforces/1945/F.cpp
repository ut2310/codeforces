#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <numeric>
#include <map> 

using namespace std;
 
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; cin >> t;
    while(t-->0) {
        ll n; cin >> n;
        vector<ll> v(n+1);
        vector<ll> p(n + 1);
        ll res = 0;
        priority_queue< pair<ll, ll> > pq;
        map<ll, ll> removed;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            pq.push(make_pair(v[i], i));
            res = max(res, v[i]);
            removed[v[i]] = 0;
        }
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            //cout << p[i] << " " << mp[p[i]] << "\n";
        }
        set< pair<ll, ll> > potions;
        //potions.insert(res);
        ll small = res;
        ll size = 1;
        for(int i = 2; i <= (n+1)/2; i++) {
            ll remove = v[p[i-1]];
            //cout << remove << " " << p[i-2] << "\n";
            removed[remove] = 1;
            if(potions.count(make_pair(remove, p[i-1])) > 0) {
                potions.erase(make_pair(remove, p[i-1]));
            }
            //cout << potions.size() << "\n";
            while(potions.size() < i) {
                pair<ll, ll> pot = pq.top();
                pq.pop();
                //cout << pot.first << " " << pot.second << "\n";
                if(removed[pot.first] == 0) {
                    //cout << "here\n";
                    potions.insert(pot);
                    small = pot.first;
                }
            }
            if(res < small * i) {
                res = small * i;
                size = i;
            }
        }
        cout << res << " " << size << "\n";
    }
}