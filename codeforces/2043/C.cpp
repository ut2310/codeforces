using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
pair<ll, ll> process(vector<ll> &a)
{
    vector<ll> ps(a.size() + 1);
    vector<ll> smax(a.size() + 1);
    vector<ll> smin(a.size() + 1);
    for(int i = 1; i <= a.size(); i++){
        ps[i] = ps[i - 1] + a[i - 1];
    }
    ll min1 = 0; ll max1 = 0;
    smin[a.size()] = ps[a.size()];
    for(int i = a.size() - 1; i >= 0; i--){
        smin[i] = min(smin[i + 1], ps[i]);
    }
    smax[a.size()] = ps[a.size()];
    for(int i = a.size() - 1; i >= 0; i--){
        smax[i] = max(smax[i + 1], ps[i]);
    }
    for(int i = 0; i <= a.size(); i++){
        min1 = min(smin[i] - ps[i], min1);
        max1 = max(smax[i] - ps[i], max1);
    }
    return {min1, max1};
}
pair<ll, ll> process2(vector<ll> &a, ll l)
{
    vector<ll> ps(a.size() + 1);
    vector<ll> smax(a.size() + 1);
    vector<ll> smin(a.size() + 1);
    for(int i = 1; i <= a.size(); i++){
        ps[i] = ps[i - 1] + a[i - 1];
    }
    ll min1 = a[l]; ll max1 = a[l];
    smin[a.size()] = ps[a.size()];
    for(int i = a.size() - 1; i >= 0; i--){
        smin[i] = min(smin[i + 1], ps[i]);
    }
    smax[a.size()] = ps[a.size()];
    for(int i = a.size() - 1; i >= 0; i--){
        smax[i] = max(smax[i + 1], ps[i]);
    }
    for(int i = 0; i <= l; i++){
        min1 = min(smin[l + 1] - ps[i], min1);
        max1 = max(smax[l + 1] - ps[i], max1);
    }
    return {min1, max1};
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        ll get_index = 0;
        set<ll> res;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] != 1 && a[i] != -1){
                get_index = i;
            }
        }
        vector<ll> a1;
        for(int i = 0; i < get_index; i++){
            a1.push_back(a[i]);
        }
        vector<ll> a2;
        for(int j = get_index + 1; j < n; j++){
            a2.push_back(a[j]);
        }
        auto get1 = process(a1);
        auto get2 = process(a2);
        auto get3 = process2(a, get_index);
        ll worst = min(get1.ff, get2.ff);
        ll best = max(get1.ss, get2.ss);

        //cout << worst << " " << best << "\n";
        for(int i = worst; i <= best; i++){
            res.insert(i);
        }
        for(int i = get3.ff; i <= get3.ss; i++){
            res.insert(i);
        }
        cout << res.size() << "\n";
        for(auto j: res){
            cout << j << " ";
        }
        cout << "\n";
        
        

    }
}