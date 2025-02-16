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
ll solve(vector<ll> &a, vector<ll> &b)
{
    ll res = 0; ll p1 = 0; ll start = a.size() - 1;
    for(int i = start; i >= 0; i--){
        if(p1 < b.size() && b[p1] < a[i]){
            res += a[i] - b[p1];
            p1++;
        }
        else{
            break;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, l, r; cin >> n >> l >> r;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector<ll> first; vector<ll> second; vector<ll> third;
        ll track = 0;
        for(int i = 1; i <= l - 1; i++){
            first.push_back(a[i]);
        }
        for(int i = l; i <= r; i++){
            second.push_back(a[i]);
            track += a[i];
        }
        for(int i = r + 1; i <= n; i++){
            third.push_back(a[i]);
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        sort(third.begin(), third.end());
        // for(auto j: second){
        //     cout << j << " ";
        // }
        // cout << "\n";
        // for(auto j: first){
        //     cout << j << " ";
        // }
        // cout << "\n";
        //cout << solve(second, first) << "\n";
        ll get = max(solve(second, first), solve(second, third));
        cout << track - get << "\n";

    }
}