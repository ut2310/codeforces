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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        set<ll> a; set <ll> b;
        ll n; cin >> n;
        for(int i = 0; i < n; i++){
            ll temp1; cin >> temp1;
            a.insert(temp1); 
        }
        for(int i = 0; i < n; i++){
            ll temp1; cin >> temp1;
            b.insert(temp1);
        }
        ll res1 = a.size();
        ll res2 = b.size();
        if(res1 * res2 >= 3){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}