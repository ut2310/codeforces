using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
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
    ll n; cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    vector<ll> posa(n + 1);
    vector<ll> posb(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        posa[b[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cout<< b[a[posa[i]]] << " ";
    }
    cout << "\n";
}