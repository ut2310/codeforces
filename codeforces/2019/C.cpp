using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
ll n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll piles = a[n - 1];
        ll cnt = 0;
        for(int i = 0; i < n - 1; i++){
            cnt += a[i];
        }
        ll track = a[n - 1];
        while(k < track - ((cnt + track) % track) && ((cnt + track) % track) != 0){
            cnt--;
            track++;
            cout << cnt << " " << track << "\n";
        }
        ll res = 0;
        if(cnt % track == 0){
            res += cnt/track;
            res += k/track;
        }
        else{
            res += (cnt + track - ((cnt + track) % track))/track;
            k -= (track - ((cnt + track) % track));
            res += k/track;
        }
        cout << res + 1 << "\n";
    }
}