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
    ll n, l, q; cin >> n >> l >> q;
    vector<ll> speeds(n);
    for(int i = 0; i < n; i++){
        cin >> speeds[i];
    }
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        a[i] = make_pair(speeds[i], speeds[n - 1]);
    }
    //the lower the number the more I can get
    sort(a.begin(), a.end(), [](const pair<ll, ll> &a1, const pair<ll, ll> &a2){
        return a1.ff * a2.ss <= a1.ss * a2.ff;
    });
    // for(int i = 0; i < n; i++){
    //     cout << a[i].ff << " " << a[i].ss << "\n";
    // }
    while(q-->0){
        ll p, w; cin >> p >> w;
        auto itr = upper_bound(a.begin(), a.end(), make_pair(p, w), [](const pair<ll, ll> &a1, const pair<ll, ll> &a2){            
            return a1.ff * a2.ss <= a1.ss * a2.ff;
        }) - a.begin();
        if(a[itr].ff * w == p * a[itr].ss){
            itr++;
        }
        //cout << itr << "\n";
        ll cnt = (n - itr);
        cout << cnt << "\n";
    }
}