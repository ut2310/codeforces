using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 22
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> adj[MAXN];
vector<ll> adj2[400005];
int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<ll> freq(20);
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < n; j++){
                if(a[j] & (1 << i)){
                    freq[i]++;
                    adj2[j].push_back(i);
                }
                else{
                    adj[i].push_back(j);
                }
            }
        }
        ll compare = x;
        bool flag = false;
        for(int i = 0; i < 20; i++){
            if(freq[i] == n){
                compare += (1 << i);
            }
            else if(freq[i] == n - 2){
                ll i1 = adj[freq[i]][0];
                ll i2 = adj[freq[i]][1];
                ll res1 = __gcd(a[i1], a[i2]);
                ll res2 = x; ll curr = (1 << 20) - 1;
                for(int j = 0; j < n; j++){
                    if(j != i1 && j != i2){
                        curr &= a[j];
                    }
                }
                res2 += curr;
                if(res1 > res2){
                    flag = true;
                    cout << "YES\n";
                    cout << 2 << " " << a[i1] << " " << a[i2] << "\n";
                    cout << n - 2 << " ";
                    for(int j = 0; j < n; j++){
                        if(j != i1 && j != i2){
                            cout << a[j] << " ";
                        }
                    }
                    cout << "\n";
                    break;
                }
            }
        }
        if(flag) break;
        for(int i = 0; i < 20; i++){
            if(freq[i] == n - 1){
                ll idx = adj[i][0];
                
            }
        }
        // now gcd must at least be greater than compare
        //
    }
}