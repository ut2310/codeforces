using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dist(pii a, pii b){
    return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    ll n, m, p; cin >> n >> m >> p;
    vector<pair<ll, ll>> judges(n + 1);
    vector<pair<ll, ll>> tar(m + 1);
    vector<pair<ll, ll>> feather(p + 1);
    for(int i = 1; i <= n; i++){
        ll a, b; cin >> a >> b;
        judges[i] = {a, b};
    }
    for(int i = 1; i<= m; i++){
        ll a, b; cin >> a >> b;
        tar[i] = {a, b};
    }
    for(int i = 1; i <= p; i++){
        ll a, b; cin >> a >> b;
        feather[i] = {a, b};
    }
    vector<pair<ll, pii>> pq;
    vector<pair<ll, pii>> pq2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pq.push_back({dist(judges[i], tar[j]), {i, j}});
        }
        for(int j = 1; j <= p; j++){
            pq2.push_back({dist(judges[i], feather[j]), {i, j}});
        }
    }
    sort(pq.begin(), pq.end());
    sort(pq2.begin(), pq2.end());
    double res = 0;
    vector<ll> v1(n + 1);
    vector<ll> v2(m + 1);
    vector<ll> v3(n + 1);
    vector<ll> v4(p + 1);
    for(auto i: pq){
        if(v1[i.ss.ff] == 0 && v2[i.ss.ss] == 0){
            res += sqrt((double) i.ff);
            v1[i.ss.ff] = 1;
            v2[i.ss.ss] = 1;
        }
    }
    for(auto i: pq2){
        if(v3[i.ss.ff] == 0 && v4[i.ss.ss] == 0){
            res += sqrt((double) i.ff);
            v3[i.ss.ff] = 1;
            v4[i.ss.ss] = 1;
        }
    }
    cout << res << "\n";
}