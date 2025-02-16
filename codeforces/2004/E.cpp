using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 10000005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll ans[MAXN];
bool check[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    ans[1] = 1; 
    ll cnt = 2;
    for(int i = 2; i <= 1e7; i++){
        ans[i] = -1;
    }
    for(int i = 2; i <= 1e7; i++){
        if(ans[i] == -1){
            if(i == 2) ans[i] = 0;
            else{
                ans[i] = cnt;
                cnt++;
            } 
            for(int j = i; j <= 1e7; j+=i){
                if(ans[j] == -1){
                    ans[j] = ans[i];
                }
            }
        }
    }
    // for(int i = 1; i<= 20; i++){
    //     cout << ans[i] << " ";
    // }
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        ll res = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            res ^= ans[a[i]];
        }
        if(res == 0){
            cout << "Bob\n";
        }
        else{
            cout << "Alice\n";
        }
    }
}