using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M;
int main()
{
    M = 1000000007;
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> x(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i == 0){
                x[i] = a[i];
            }
            else{
                x[i] = a[i]^x[i - 1];
            }
        }
        map<ll, ll> mp;
        mp[0] = 3;
        for(int i = 1; i < n; i++){
            if(mp.count(x[i - 1]) > 0){
                mp[x[i - 1]] *= 3;
                mp[x[i - 1]] %= M;
            }
            if(mp.count(x[i]) > 0){
                mp[x[i - 1]] += 2 * mp[x[i]];
                mp[x[i - 1]] %= M;
            }
            // for(auto j: mp){
            //     cout << j.first << " " << j.second << "\n";
            // }
            // cout << "\n\n\n";
        }
        ll res = 0;
        for(auto j: mp){
            res += j.second;
            res %= M;
        }
        if(res < 0) res += M;
        cout << res << "\n";
    }
}