using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, d; cin >> n >> d;
        vector<ll> res; res.push_back(1);
        if(d % 3 == 0 || n >= 3){
            res.push_back(3);
        }
        if(d % 5 == 0){
            res.push_back(5);
        }
        if(d % 7 == 0 || n >= 3){
            res.push_back(7);
        }
        if(d %9 == 0 || (d % 3 ==0 && n >= 3) || (n >= 6)){
            res.push_back(9);
        }
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}