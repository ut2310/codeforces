using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k; cin >> n >> k;
        if(n == 1){
            cout << "1\n";
            cout << "1\n";
        }
        else if(k == 1 || k == n){
            cout << "-1\n";
        }
        else{
            if((k - 1) % 2 == 0){
                cout << "3\n";
                cout << 1 << " " << k - 1 << " " << k + 2 << "\n";
            }
            else{
                cout << "3\n";
                cout << 1 << " " << k << " " << k + 1 << "\n";
            }
        }

    }
}