using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ll n; cin >> n;
    vector<ll> x;
    vector<ll> y;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll res1 = -1;
    ll res2 = -1;
    for(int i = 0; i < n; i++){
        if(i + 1 >= (n - (i + 1))){
            res1 = x[i];
            res2 = y[i];
            break;
        }
    }
    cout << res1 << " " << res2 << "\n";
}