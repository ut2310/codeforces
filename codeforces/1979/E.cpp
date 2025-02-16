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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, d; cin >> n >> d;
        vector<pair<ll, ll>> a(n);
        map<pii, ll> index;
        set<pii> store;
        map<ll, set<ll>> mp;
        map<ll, set<ll>> mm;
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
            store.insert({a[i].first, a[i].second});
            index[{a[i].first, a[i].second}] = i + 1;
            mp[a[i].second - a[i].first].insert(a[i].first);
            mm[a[i].second + a[i].first].insert(a[i].first);
        }
        bool flag = false;
        for(int i = 0; i < n; i++){
            ll x = a[i].first; ll nx = a[i].first + d/2;
            ll y = a[i].second; 
            for(int j = -1; j <= 1; j+=2){
                ll ny = y + d/2 * j;
                if(store.count({nx, ny}) == 0){
                    continue;
                }
                if(j == 1){
                    //look at x + y + d b1: x - d/2 & b2: x, x + y - d
                    auto itr = mp[y - x + d].lower_bound(x - d/2);
                    auto itr2 = mp[y - x - d].lower_bound(x + d/2);
                    if(itr != mp[y - x + d].end() && *itr <= x){
                        ll a1 = i + 1; ll a2 = index[{nx, ny}]; ll a3 = index[{*itr, *itr + y - x + d}];
                        if(a1 != a2 && a2 != a3 && a1 != a3){
                            cout << a1 << " " << a2 << " " << a3 << "\n";
                            flag = true;
                            break;
                        }
                    }
                    if(itr2 != mp[y - x - d].end() && *itr2 <= (x + d)){
                        ll a1 = i + 1; ll a2 = index[{nx, ny}]; ll a3 = index[{*itr2, *itr2 + y - x - d}];
                        if(a1 != a2 && a2 != a3 && a1 != a3){
                            cout << a1 << " " << a2 << " " << a3 << "\n";
                            flag = true;
                            break;
                        }
                    }
                }
                else{
                    //look at x + y + d b1: x - d/2 & b2: x, x + y - d
                    auto itr = mm[y + x + d].lower_bound(x + d/2);
                    auto itr2 = mm[y + x - d].lower_bound(x - d/2);
                    if(itr != mm[y + x + d].end() && *itr <= (x + d)){
                        ll a1 = i + 1; ll a2 = index[{nx, ny}]; ll a3 = index[{*itr, y + x + d - *itr}];
                        if(a1 != a2 && a2 != a3 && a1 != a3){
                            cout << a1 << " " << a2 << " " << a3 << "\n";
                            flag = true;
                            break;
                        }
                    }
                    if(itr2 != mm[y + x - d].end() && *itr2 <= x){
                        ll a1 = i + 1; ll a2 = index[{nx, ny}]; ll a3 = index[{*itr2, y + x - d - *itr2}];
                        if(a1 != a2 && a2 != a3 && a1 != a3){
                            cout << a1 << " " << a2 << " " << a3 << "\n";
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if(flag) break;
        }
        if(!flag){
            cout << "0 0 0\n";
        }
    }
}