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
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll res = n * (n + 1)/2;
        //binary search on the number of bessie cows
        ll low = 0; ll high = n;
        while(low < high){
            ll mid = (low + high)/2;
            ll ans = mid * (mid + 1)/2;
            ll addOn = mid; ll track = 0; ll p1 = 0; 
            for(int i = 0; i < mid; i++){
                track += addOn;
                addOn--;
                while(p1 < n && a[p1] < track){
                    p1++;
                }
                if(p1 < n) p1++;
            }
            if(p1 < n){
                res = min(res, a[n - 1]);
                low = mid + 1;
            }
            else{
                high = mid;
                res = min(res,  ans);
            }
        }
        cout << res << "\n";
    }
}