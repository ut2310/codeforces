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
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<ll> pmax(n); pmax[0] = a[0];
        for(int i = 1; i < n; i++){
            pmax[i] = max(a[i], pmax[i - 1]);
        }
        vector<ll> dp(n);
        dp[n - 1] = n - 1;
        map<ll, ll> track; track[a[n - 1]] = n - 1;
        for(int i = n - 2; i >= 0; i--){
            auto it = track.lower_bound(pmax[i]); 
            if(it != track.begin()){
                it = prev(it); 
                dp[i] = it->second;
            }
            else{
                dp[i] = i;
            }
            auto get = track.begin();
            if(a[i] < get->first){
                track[a[i]] = i;
            }
            //cout << i << " " << dp[i] << "\n";
        }
        vector<ll> res(n);
        res[n - 1] = pmax[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(dp[i] == i){
                res[i] = pmax[i];
            }
            else{
                res[i] = res[dp[i]];
            }
        }
        for(int i = 0; i < n; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}