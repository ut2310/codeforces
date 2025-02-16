using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
bool comp(pair<ll, ll> a, pair<ll, ll> b){

}
int main()
{
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        ll l, r; cin >> l >> r;
        a[i].ff = l - r; a[i].ss = (l + r);
    }
    sort(a.begin(), a.end(), [](pii a1, pii a2) -> bool{
        if(a1.first != a2.first) return a1.ff < a2.ff;
        else return a2.ss < a1.ss;
    });
    vector<int> dp;
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(dp.begin(), dp.end(), a[i].ss) - dp.begin();
		if (pos == dp.size()) {

			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smaller
			dp[pos] = i;
		}
	}

}