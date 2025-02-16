using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
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
        if(n % 2== 0){
            ll track = 1;
            for(int i = 0; i < n/2 ; i++){
                cout << track << " " << track << " ";
                track++;
            }
            continue;
        }
        else{
            if(n > 25){
                vector<ll> res = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 13, 1, 12};
                for(int i = 28; i <= n; i++){
                    res.push_back(i/2);
                }
                for(int i = 0; i < n; i++){
                    cout << res[i] << " ";
                }
                cout << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
       
    }
}