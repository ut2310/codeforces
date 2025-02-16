using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll arr[MAXN][MAXN], dp[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll r, c, x; cin >> r >> c >> x;
    for(int i = 1 ; i <= r; i++){
        string s; cin >> s;
        for(int j = 0; j < c; j++){
            ll val = s[j] - '0';
            arr[i][j + 1] = val;
        }
    }
    bool flag = true;
    for(int i = 1; i <= r - 1; i++){
        for(int j = 1; j <= c - 1; j++){
            ll a1 = arr[i][j]; ll a2 = arr[i + 1][j]; ll a3 = arr[i][j + 1]; ll a4 = arr[i + 1][j + 1];
            if(!(a2 - a1 == a4 - a3 || a1 == a4 || a2 == a3)){
                flag = false;
            }
        }
    }
    if(flag){
        dp[1][1] = 0;
        for(int j = 2; j <= c; j++){
            dp[1][j] = dp[1][j - 1] + pow((arr[1][j - 1] - arr[1][j]), x);
        }
        for(int j = 2; j <= r; j++){
            dp[j][1] = dp[j - 1][1] + pow(arr[j - 1][1] - arr[j][1], x);
        }
        for(int i = 2; i <= r; i++){
            for(int j = 2; j <= c; j++){
                dp[i][j] += min(pow((arr[i][j - 1] - arr[i][j]), x) + dp[i][j - 1], pow((arr[i - 1][j] - arr[i][j]), x) + dp[i - 1][j]);
            }
        }
    }
    
    ll q; cin >> q;
    while(q-->0){
        ll rs, cs, rf, cf; cin >> rs >> cs >> rf >> cf;
        if(x == 1){
            cout << arr[rs][cs] - arr[rf][cf] << "\n";
            continue;
        } 
        if(!flag){
            cout << "INVALID\n";
            continue;
        }
        else{
            cout << dp[rf][cf] - dp[rs][cs] << "\n";
        }

    }
}