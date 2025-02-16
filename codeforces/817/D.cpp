#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<pair<ll, ll>> track;
    track.push({1e7, -1});
    vector<pair<ll, ll>> res1(n);
    for(int i = 0; i < n; i++){
        while(track.size() > 0 &&  track.top().first < a[i]){
            track.pop();
        }
        res1[i].first = track.top().second + 1;
        track.push({a[i], i});
    }
    while(!track.empty()) track.pop();
    track.push({1e7, n});
    for(int i = n - 1; i >= 0; i--){
        while(track.size() > 0 &&  track.top().first <= a[i]){
            track.pop();
        }
        res1[i].second = track.top().second - 1;
        track.push({a[i], i});
    }
    while(!track.empty()) track.pop();
    vector<pair<ll, ll>> res2(n);
    track.push({0, -1});
    for(int i = 0; i < n; i++){
        while(track.size() > 0 &&  track.top().first > a[i]){
            track.pop();
        }
        res2[i].first = track.top().second + 1;
        track.push({a[i], i});
    }
    while(!track.empty()) track.pop();
    track.push({0, n});
    for(int i = n - 1; i >= 0; i--){
        while(track.size() > 0 &&  track.top().first >= a[i]){
            track.pop();
        }
        res2[i].second = track.top().second - 1;
        track.push({a[i], i});
    }
    // for(int i = 0; i < n; i++){
    //     cout << res1[i].first << " " << res1[i].second << " " << res2[i].first << " " << res2[i].second << "\n";
    // }
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll num_max = (i - res1[i].first + 1) * (res1[i].second - i + 1);
        res += num_max * a[i];
        ll num_min = (i - res2[i].first + 1) * (res2[i].second - i + 1);
        res -= num_min * a[i];
    }
    cout << res << "\n";
}