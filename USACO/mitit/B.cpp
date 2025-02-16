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

int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> i0; vector<ll> o0;
        vector<ll> i1; vector<ll> o1;
        for(int i = 0; i < n; i++){
            ll x, y; cin >> x >> y;
            if(y == 0) i0.push_back(x);
            if(y == 1) i1.push_back(x);
        }
        for(int i = 0; i < n; i++){
            ll x, y; cin >> x >> y;
            if(y == 0) o0.push_back(x);
            if(y == 1) o1.push_back(x);
        }
        //cout << o1.size() << " " << i1.size() << "\n";
        ll x = o1.size(); ll y = i1.size();
        if(x < y){
            //cout << "YES\n";
            o0.swap(o1);
            i0.swap(i1);
        }
        //guarantee the 1s have greater output size
        sort(o0.begin(), o0.end()); sort(i0.begin(), i0.end());
        sort(i1.begin(), i1.end()); sort(o1.begin(), o1.end());
        //guarantee o1 is greater than i1
        // for(auto j: o1){
        //     cout << j << " ";
        // }
        // cout << "\n";
        // for(auto j: i1){
        //     cout << j << " ";
        // }
        // cout << "\n";
        ll p2 = o1.size() - 1;
        vector<ll> left;
        for(int p1 = i1.size() - 1; p1 >= 0; p1--){
            while(p2 >= 0 && i1[p1] * 2 < o1[p2]) {
                left.push_back(o1[p2]);
                p2--;
            }
            if(p2 >= 0 && i1[p1] * 2 >= o1[p2]){
                p2--;
            }
        }
        for(ll x = p2; x >= 0; x--){
            left.push_back(o1[x]);
        }
        // for(auto j: left){
        //     cout << j << " ";
        // }
        // cout << "\n";
        //we have our left elements
        //check in i0 if our left elements can work
        multiset<ll> o00;
        for(auto j: o0) o00.insert(j);
        vector<ll> visited(i0.size());
        bool flag = true;
        for(int p1 = 0; p1 < i0.size(); p1++){
            ll target = 2 * i0[p1];
            if(o00.size() == 0) break;
            if(*o00.begin() > target){
                continue;
            } 
            visited[p1] = 1;
            auto itr = prev(o00.upper_bound(target));
            o00.erase(itr);
        }
        if(o00.size() != 0){
            flag = false;
        }
        vector<ll> left2;
        for(int j = 0; j < i0.size(); j++){
            if(visited[j] == 0){
                left2.push_back(i0[j]);
            }
        }
        //compare left2 with left
        ll x1 = left.size(); ll x2 = left2.size();
        if(x1 != x2) flag = false;
        sort(left.begin(), left.end()); sort(left2.begin(), left2.end());
        for(int i = 0; i < left.size(); i++){
            if(left2[i] < left[i]) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }
}