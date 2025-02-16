using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505

int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        ll node = -1;
        for(int i = 2; i <= n - 1; i++){
            cout << "? 1 " << i << "\n";
            cout.flush();
            ll temp1; cin >> temp1;
            if(temp1 == 0){
                node = i;
                break;
            }
        }
        vector<ll> p(n);
        // we know (1 - node - 1) have parent 0, and node has parent 1
        p[node] = 1;
        ll p1 = 2;
        ll p2 = node + 1;
        while(p2 <= n - 1){
            if(p2 == p1 + 1){
                while(p2 <= n - 1){
                    p[p2] = p1;
                    p2++; p1++;
                }
                continue;
            }
            cout << "? " << p1 << " " << p2 << "\n";
            cout.flush();
            ll temp1; cin >> temp1;
            if(temp1 == 0){
                p[p2] = p1;
                p1++; p2++;
            }
            else{
                p1++;
            }
        }
        cout << "! ";
        for(int i = 1; i <= n - 1; i++){
            cout << p[i] << " ";
        }
        cout << "\n";
        cout.flush();
    }
}