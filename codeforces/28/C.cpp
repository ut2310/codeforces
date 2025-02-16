using namespace std;
#include <bits/stdc++.h>
#define ll long double
#define MAXN 51
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[MAXN][MAXN][MAXN];
int main()
{
    ll n, m; cin >> n >> m;
    vector<ll> a(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        dp[i][0][0] = 1;
    }
    for(int j = 1; j <= n; j++){
        for(int k = 1; k <= j; k++){
            for(int j1 = 1; j1 <= j; j1++){
                if((j1 + a[1] - 1)/a[1] == k){
                    dp[1][j][k]++;
                }
            }
            //j people k is the max number of ways so ceiling(j/a[1]) = k
        }
    }
    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= j; k++){
                // j people, k is the max number of ways
                for(int j1 = 0; j1 <= j; j1++){
                    dp[i][j][k] += dp[i - 1][j - j1][k]; // we have j1 people in the ith position
                    if((j1 + a[i] - 1)/a[i] == k){
                        dp[i][j][k] += dp[i - 1][j - j1][k - 1];
                    }
                } 
            }
        }
    }
    ll total = 0;

}