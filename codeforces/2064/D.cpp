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
ll dp[MAXN][31];
ll arr[MAXN];
ll prefxor[MAXN];
ll setBitNumber(ll n)
{
    if (n == 0)
        return 0;
 
    ll msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
    return msb;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, q; cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            prefxor[i] = prefxor[i - 1] ^ arr[i];
        }
        vector<ll> update(31);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 30; j++){
                if((1 << j) <= arr[i]){
                    update[j] = i;
                }
                dp[i][j] = update[j];
                //cout << i << " " << j << " " << dp[i][j] << "\n";
            }
        }
        for(int i = 0; i < q; i++){
            ll x; cin >> x;
            ll curr = n;
            ll track_bit = setBitNumber(x);
            ll res = 0;
            while(dp[curr][track_bit] <= curr){
                //we can guarentee go here
                ll index = dp[curr][track_bit];
                //cout << curr << " " << track_bit << " " << index << " " << (x ^ (prefxor[index - 1] ^ prefxor[n]))  << "\n";
                if(index == 0){
                    res = n;
                    break;
                }
                if(arr[index] <= (x ^ (prefxor[index] ^ prefxor[n])))
                {
                    ll new_number = x ^ (prefxor[index - 1] ^ prefxor[n]);
                    track_bit = setBitNumber(new_number);
                    curr = index - 1;
                }
                else{
                    res = n - index;
                    break;
                }
            }
            cout << res << " ";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 30; j++){
                dp[i][j] = 0;
            }
            arr[i] = 0; prefxor[i] = 0;
        }
    }
}