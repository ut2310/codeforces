using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> p(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        vector<ll> visited(n + 1);
        ll res = 0;
        for(int i =1 ; i <= n; i++){
            if(visited[i] == 0){
                ll size = 0;
                ll temp = i;
                while(visited[temp] == 0){
                    visited[temp] = 1;
                    temp = p[temp];
                    size++;
                }
                res += (size + 1)/2 - 1;
            }
        }
        cout << res << "\n";
    }
}