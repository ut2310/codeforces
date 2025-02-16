using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k; cin >> n >> k;
        vector<ll> a(n + 1);
        ll curr = 1;
        ll end = n;
        ll start = 1;
        while(curr <= n){
            for(int i = curr; i < min(n + 1, curr + (k - 1)); i++){
                a[i] = end;
                end--;
            }
            curr += k - 1;
            if(curr > n){
                break;
            }
            a[curr] = start; curr++; start++;
            
        }
        for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}