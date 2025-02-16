using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 755
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
    ll N, Q; cin >> N;
    vector<ll> a1(N);
    for(int i = 0; i < N; i++){
        cin >> a1[i];
    }
    sort(a1.begin(), a1.end());
    vector<ll> ps(N + 1);
    for(int i = 1; i <= N; i++){
        ps[i] = a1[i - 1] + ps[i - 1];
    }
    cin >> Q;
    while(Q-->0){
        ll a, b; cin >> a >> b;
        ll x = b * N / (a + b);
        ll res = a * (a1[x] * x - ps[x]) + b * ((ps[N] - ps[x]) - ((N - x) * a1[x]));
        cout << res << "\n";
    }
}