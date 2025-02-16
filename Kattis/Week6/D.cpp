using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
set<pair<ll, ll>> store;
int main()
{
    ll  n, r; cin >> n >> r;
    string s; cin >> s;
    for(int i = 0; i * i * i* i <= r; i++){
        for(int j = 0; j * j <= r - (i * i * i * i); j++){
            store.insert({i, j});
            store.insert({-i, j});
            store.insert({i, -j});
            store.insert({-i, -j});
        }
    }
    //for each x look at best y
    map<ll, ll> xtoy;
    for(int i = 0; i * i * i *i <= r; i++){
        ll a = r - i * i * i * i;
        ll low = 0;
        ll high = a;
        while(low < high){
            ll mid = (low + high + 1)/2;
            if(mid * mid <= a){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        xtoy[i] = low;
    }
    //for each y look at best x
    map<ll, ll> ytox;
    for(int i = 0; i * i <= r; i++){
        ll a = r - i * i;
        ll low = 0;
        ll high = a;
        while(low < high){
            ll mid = (low + high + 1)/2;
            if(mid * mid * mid * mid <= a){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        ytox[i] = low;
    }
    for(auto j: xtoy){
        cout << j.first << " " << j.second << "\n";
    }
    for(auto j: ytox){
        cout << j.first << " " << j.second << "\n";
    }


    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R' || s[i] == 'L'){
            //for
        }
    }
}