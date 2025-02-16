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
    vector<ll> a(n);
    vector<ll> ps(n);
    ll og_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        og_sum += abs(a[i]);
        if(a[i] < 0) ps[i] = 3 * a[i];
        else ps[i] = a[i];
    }
    //just get max subarray sum from an array
    ll max_subarray_sum = 0;
    ll track = 0;
    for(int i = 0; i < n; i++){
        track += ps[i];
        if(track < 0) track = 0;
        else max_subarray_sum = max(track, max_subarray_sum);
    }
    ll res = og_sum + max_subarray_sum;
    cout << res << "\n";
}