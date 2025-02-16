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

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n + 1);
        vector<ll> pos(n + 1);
        set<ll> store;
        for(int i = 1; i <= n; i++){
            cin >> a[i]; store.insert(a[i]);
            pos[a[i]] = i;
        }
        ll res = -1;
        for(int i = 1; i <= n; i++){
            if(store.count(i) == 0){
                res = i;
                break;
            }
        }
        if(res != -1){
            ll diff = res - 1; if(diff == 0) diff += 2;
            cout << "? " << res << " " << diff << endl;
            ll res2; cin >> res2;
            if(res2 == 0){
                cout << "! A" << endl;
            }
            else{
                cout << "! B" << endl;
            }
        }
        else{
            ll res2, res3;
            cout << "? " << pos[1] << " " << pos[n] << endl;
            cin >> res2;
            cout << "? " << pos[n] << " " << pos[1] << endl;
            cin >> res3;
            if(res2 >= n - 1 && res3 >= n - 1){
                cout << "! B" << endl;
            }
            else{
                cout << "! A" << endl;
            }

        }
    }
}