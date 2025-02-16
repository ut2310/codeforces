using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto sn = a;
    sort(sn.begin(), sn.end());
    ll res = n * n;
    map<ll, ll> visited;
    ll track = n - 1;
    ll diff = 0;
    bool flag = false; //2 3 4 0 0 5 5
    ll least = 1e11;
    for(int i = n - 1; i >= 0; i--){
        least = min(least, a[i]);
        ll cnt = n - i;
        visited[a[i]]++;
        while(visited[sn[track]] >= 1){
            visited[sn[track]]--;
            track--;   
        }
        if(a[i] == sn[track + 1] && least == a[i]){
            diff++;
        }
        else{
            diff = 0; //we need to check how many of the last elements we place already worked as long as there is nothing further than can be placed here
        } 
        // cout << track << " " << cnt << "hi\n";
        // for(auto j: visited){
        //     cout << j.first << " " << j.second << "\n";
        // }
        // cout << "\n";
        res = min(res, (cnt - diff) * (cnt - diff) + (track + 1) * (track + 1));
    }
    map<ll, ll> visited2;
    track = 0;
    diff = 0;
    ll most = -1;
    for(int i = 0; i < n; i++){
        most = max(a[i], most);
        ll cnt = i + 1;
        visited2[a[i]]++;
        while(visited2[sn[track]] >= 1){
            visited2[sn[track]]--;
            track++;
        }
        if(a[i] == sn[track - 1] && most == a[i]) diff++;
        else diff = 0;
        if (flag) diff = 0;
        res =  min(res, (cnt - diff) * (cnt - diff) + (n - track) * (n - track));
    }
    cout << res << "\n";
}