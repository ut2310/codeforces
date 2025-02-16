using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    pair<ll, ll> curr = {0, 0};
    vector<pair<ll, ll>> pref(n + 1);
    ll t = 0;
    map<pair<ll, ll>, vector<ll>> mp;
    mp[curr].push_back(t);
    for(int i = 0; i < n; i++){
        t++;
        if(s[i] == 'R'){
            curr.first++;
        }
        else if(s[i] == 'L'){
            curr.first--;
        }
        else if(s[i] == 'D'){
            curr.second--;
        }
        else if(s[i] == 'U'){
            curr.second++;
        }
        mp[curr].push_back(t);
        pref[t] = curr;
    }
    t = 0;
    curr = {0, 0};
    vector<pair<ll, ll>> pref2(n + 1);
    map<pair<ll, ll>, vector<ll>> mp2;
    mp2[curr].push_back(t);
    for(int i = n - 1; i >= 0; i--){
        t++;
        if(s[i] == 'R'){
            curr.first++;
        }
        else if(s[i] == 'L'){
            curr.first--;
        }
        else if(s[i] == 'D'){
            curr.second--;
        }
        else if(s[i] == 'U'){
            curr.second++;
        }
        mp2[curr].push_back(t);
        pref2[t] = curr;
    }
    for(int i = 0; i < q; i++){
        ll x, y, l, r; cin >> x >> y >> l >> r;
        bool flag = false;
        vector<ll> &get = mp[{x, y}];
        if(get.size() > 0){
            if(get[0] < l || get[get.size() - 1] >= r){
                flag = true;
            }
        }
        pair<ll, ll> start = pref[l - 1]; pair<ll, ll> rstart = pref2[n - r]; //fix this soon
        pair<ll, ll> lookFor = {x - start.ff + rstart.ff, y - start.ss + rstart.ss};
        vector<ll> &get2 = mp2[lookFor];
        if(get2.size() > 0){
            ll r1 = (n + 1) - l;
            ll l1 = (n + 1) - r;
            auto itr = lower_bound(get2.begin(), get2.end(), l1);
            if(itr - get2.begin() < get2.size()){
                if(*itr <= r1){
                    flag = true;    
                }
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
        //in the reverse string we are looking at r 

    }
    // for(auto j: mp){
    //     cout << j.ff.ff << " " << j.ff.ss << "\n";
    //     for(auto j1: j.ss){
    //         cout << j1 << " ";
    //     }
    //     cout << "\n";
    // }
}