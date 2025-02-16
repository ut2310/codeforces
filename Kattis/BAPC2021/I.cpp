using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ll n; cin >> n;
    vector<ll> t(n); vector<ll> s(n);
    vector<pair<ll, ll>> input(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        input[i] = {s[i], t[i]};
    }
    sort(input.begin(), input.end());
    ll total_time = 0;
    ll res = 1;
    for(int i = 0; i < input.size(); i++){
        if(input[i].first == -1) continue;
        total_time += input[i].second;
        res = max(res , (total_time + input[i].first - 1)/input[i].first);
    }
    cout << res << "\n";
}