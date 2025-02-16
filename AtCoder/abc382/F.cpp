using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ll h, w, n; cin >> h >> w >> n;
    vector<pair<ll, pair<ll, ll>>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss.ff >> a[i].ss.ss;
    }
    sort(a.begin(), a.end());
    vector<ll> res(n);
    for(int i = n - 1; i >= 0; i--){
        res[i] = h;
        
    }
}