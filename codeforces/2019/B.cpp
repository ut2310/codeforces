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
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<ll, ll> freq;
        for(int i = 0; i < n - 1; i++){
            freq[(i + 1) * (n - (i + 1))] += a[i + 1] - a[i] - 1;
            freq[(i + 1) * (n - (i)) - 1] += 1;
        }
        freq[n - 1] += 1;
        vector<ll> queries(q);
        for(int i = 0; i < q; i++){
            ll q; cin >> queries[i];
        }
        for(int i = 0; i < q; i++){
            cout << freq[queries[i]] << " ";
        }
        cout << "\n";
    }
}