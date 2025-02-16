using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
ll find_lis(vector<ll> &a) {
	vector<ll> dp;
	for (ll i : a) {
		ll pos = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			// we can have a new, longer increasing subsequence!
			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smaller
			dp[pos] = i;
		}
	}
	return dp.size();
}
ll process(ll l, ll r, vector<ll> &a)
{
    if(a[l] + r - l > a[r]){
        return -1;
    }
    vector<ll> get_pos;
    ll total = r - l - 1; //total elements we are looking at
    ll track = r - l - 1;
    for(int i = l + 1; i < r; i++){
        if(a[i] >= a[l] + i - l && a[i] + r - i <= a[r]){
            get_pos.push_back(track + a[i]);
        }
        track--;
    }
    //need longest increasing subsequence in get_pos
    ll lis = find_lis(get_pos);
    return total - lis;
    //answer is just total - length of longest increasing subsequence   
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 2);
    vector<ll> b(k + 2);
    a[0] = -1e10;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n + 1] = 1e10;
    b.push_back(0);
    for(int i = 1; i <= k; i++){
        cin >> b[i];
    }
    b[k + 1] = n + 1;
    ll p1 = 1;
    bool flag = true;
    ll final_res = 0;
    for(int i = 1; i <= n + 1; i++){
        //cout << i << " " << b[p1] << "\n";
        if(i == b[p1]){
            ll res = process(b[p1 - 1], b[p1], a);
            if(res == -1){
                flag = false;
                break;
            }
            else{
                //cout << res << "\n";
                final_res += res;
            }
            p1++;
        }
    }
    //cout << "\n";
    if(!flag){
        cout << "-1\n";
    }
    else{
        cout << final_res << "\n";
    }
}