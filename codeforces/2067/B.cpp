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
        vector<ll> a(n); set<ll> b;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll b_size = 0;
        for(int i = a.size() - 1; i >= 0; i--){
            ll num = a[i];
            if(b.size() == 0){
                b_size++;
                b.insert(a[i]);
                continue;
            }
            ll p1 = *b.rbegin();
            while(num < p1){
                if(b.count(num) > 0){
                    num++;
                }
                else{
                    break;
                }
            }
            if(num == p1){
                b.erase(p1);
            }
            else{
                b.insert(num);
                b_size++;
            }
        }
        if(b_size <= n/2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}