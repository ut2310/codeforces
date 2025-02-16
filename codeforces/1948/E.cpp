using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll a, b; cin >> a >> b;
        ll curr = 1;
        vector<ll> res(a + 1);
        vector<ll> res2(a + 1);
        ll cnt = 0;
        while(curr <= a){
            ll start = curr;
            ll end = min(a, curr + b - 1);
            res[(start + end + 1)/2] = end;
            if(start == end){
                curr = end + 1;
                cnt++;
                res2[end] = cnt;
                continue;
            }
            res[(start + end - 1)/2] = start;
            for(int i = (start + end + 1)/2 + 1; i <= end; i++){
                res[i] = res[i - 1] - 1;
            }
            // for(int i = 1; i <= a; i++){
            //     cout << res[i] << " ";
            // }
            // cout << "\n";
            for(int i = (start + end - 1)/2 - 1; i >= start; i--){
                res[i] = res[i + 1] + 1;
            }
            curr = end + 1;
            cnt++;
            for(int i = start; i <= end; i++){
                res2[i] = cnt;
            }
        }
        for(int i = 1; i <= a; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << cnt << "\n";
        for(int i = 1; i <= a; i++){
            cout << res2[i] << " ";
        }
        cout << "\n";
    }
}