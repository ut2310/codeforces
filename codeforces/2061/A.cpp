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
        vector<ll> a(n);
        ll res= 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2 == 1){
                res++;
            }
            else flag = true;

        }
        if(flag) res++;
        if(!flag) res--;
        cout << res << "\n";
    }
}