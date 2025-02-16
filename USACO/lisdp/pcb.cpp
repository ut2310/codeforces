using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 305
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
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<ll> ps(n + 1);
    set<pair<ll, ll>> curr;
    for(int i = 0; i < n; i++){
        auto itr = curr.lower_bound({a[i].second, i});
        if(itr != curr.end()){
            
        }
    }
}