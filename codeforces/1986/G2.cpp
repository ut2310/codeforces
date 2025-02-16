using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 500005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> arr[MAXN];
vector<ll> adj1[MAXN]; //this stores all things such that 
pair<ll, ll> store[MAXN];
ll freq[MAXN];
//vector<ll> get_val[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll t; cin >> t;
    for(int i = 1; i <= 5e5; i++){
        for(int j = i; j <= 5e5; j+=i){
            arr[j].push_back(i);
        }
    }
    while(t-->0){
        ll n; cin >> n;
        long long cnt = 0;
        long long res = 0;
        for(int i = 1; i <= n; i++){
            ll temp; cin >> temp;
            ll get = gcd(temp, i);
            temp/= get;
            if(i/get == 1) cnt++;
            for(auto j: arr[temp]){
                adj1[j].push_back(i/get);
            }
            store[i] = {i/get, temp};
        }
        sort(store, store + n + 1);
        vector<ll> remove;
        for(int i = 1; i <= n; i++){
            ll pj = store[i].ss;
            if(store[i].ff != store[i - 1].ff){
                for(auto rem: remove){
                    freq[rem] = 0;
                }
                remove.clear();
                for(auto thing: adj1[store[i].ff]){
                    freq[thing]++;
                    remove.push_back(thing);
                }
            } 
            for(auto factor: arr[pj]){
                res += freq[factor];
            }
        }
        cout << (res - cnt)/2 << "\n";
        for(int i = 1; i <= n; i++){
            adj1[i].clear();
            store[i] = {0, 0};
            freq[i] = 0;
        }

    }
}
