using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n/2; i++){
            //i, n - 1 - i
            if((a[i] == a[i - 1] && a[n - 1 - i] != a[i - 1]) || (a[n - i] == a[n - 1 - i] && a[i] != a[n - i])){
                ll temp = a[i];
                a[i] = a[n - 1 - i];
                a[n - 1 - i] = temp;
            }
        }
        ll res= 0;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i - 1]){
                res++;
            }
        }
        cout << res << "\n";
    }
}