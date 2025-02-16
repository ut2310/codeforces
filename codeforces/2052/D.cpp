using namespace std;
#include <bits/stdc++.h>
#define ll int


int main()
{
    ll n; cin >> n;
    vector<pair<ll, ll>> a;
    set<ll> first;
    set<ll> third;
    ll x = -1;
    ll y = -1;
    vector<ll> type(n + 1);
    for(int i = 0; i < n; i++){
        string s1, s2; cin >> s1 >> s2;
        ll n1, n2;
        if(s1 == "unset" && s2 == "false"){
            type[i + 1] = 1;
        }
        else if(s1 == "set" && s2 == "true"){
            type[i + 1] = 2e5;
            x = i + 1;
        }
        else if(s1 == "set" && s2 == "false"){
            type[i + 1] = 4e5;
        }
        if(s2 == "unset" && s2 == "true"){
            type[i + 1] = 6e5;
            y = i + 1;
        }
    }
    ll cond; cin >> cond;
    vector<ll> check(n + 1);
    vector<pair<ll, ll>> check;
    bool flag = true;
    while(cond-->0){
        ll a, b; cin >> a >> b;
        if(type[a] < type[b]){
            check[a] = true;
            continue;
        }
        else{
            if(type[b] == type[a]){
                if(type[b] == 1){
                    //check.push_back({a, b});
                }
            }
            else if(type[b] == 1 && type[a] > 1){
                type[b] = 8e5;
            }
            else{
                flag = false;
            }
        }
        //a must occur before b
    }
    //if unset is false that means it was originally false, and msut occur first
    set<ll> first;
    for
}