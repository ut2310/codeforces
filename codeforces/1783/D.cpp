using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200001
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp2[301][MAXN];
ll M;
int main()
{
    M = 998244353;
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> dp(n - 1);
    dp[0] = 1;
    dp2[0][a[1] + 100000]++;
    for(int i = 1; i < n - 1; i++){
        dp[i] = dp[i - 1] * 2 - dp2[i - 1][100000];
        dp[i] %= M;
        if(dp[i]< 0) dp[i] += M;
        for(int j = 0; j <= 200000; j++){
            ll get = dp2[i - 1][j];
            ll acc_value = j - 1e5;
            if(get == 0) continue;
            if(acc_value == 0){
                dp2[i][a[i + 1] + acc_value + 100000] += get;
                dp2[i][a[i + 1] + acc_value + 100000] %= M;
            }
            else{
                dp2[i][a[i + 1] + acc_value + 100000] += get;
                dp2[i][a[i + 1] + acc_value + 100000] %= M;
                dp2[i][a[i + 1] - acc_value + 100000] += get;
                dp2[i][a[i + 1] - acc_value + 100000] %= M;
            }
        }
        //need to keep track of is a[i + 1] equal to zero, its when the (a[i] == a[i + 1]) or when(a[i] == -(a[i + 1]))
        //need to update all possible values i in dp2[i - 1], 
        //dp2[i][]
    }
    // for(int i = 0; i < n - 1; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    ll res = dp[n - 2] % M;
    if(res < 0) res+= M;
    cout << res << "\n";
}