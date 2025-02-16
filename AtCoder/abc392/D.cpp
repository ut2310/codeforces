using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
map<ll, ll> arr[MAXN];
ll store[MAXN];
ll store2[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    ll n; cin >> n;

    for(int i = 0; i < n; i++){
        ll m; cin >> m;
        for(int j  = 0; j < m; j++){
            ll temp; cin >> temp;
            arr[i][temp]++;
        }
        store[i] = arr[i].size();
        store2[i] = m;
    }
    double res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double ans = 0;
            
            for(auto k: arr[j]){
                if(arr[i].count(k.first) > 0){
                    ans += arr[i][k.first] * k.second;
                }
            }
            res = max(res, (double) ans/((double) store2[i] * store2[j]));
        }
    }
    cout << res << "\n";


}