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
        ll n; cin >> n;
        if(n % 33 == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
}