using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
double dp[MAXN][MAXN];
int main()
{
    ll n, x; cin >> n >> x;
    vector<double> a(n + 1);
    for(int i = 0; i < n; i++){
        cin >> a[i + 1];
    } 
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i - 1][j] * (100 - a[i])/(double)(100);
            if(j > 0) dp[i][j] += dp[i - 1][j - 1] * (a[i])/100;
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    vector<double> ev(x + 1);
    ev[1] = 1/(1 - dp[n][0]);
    for(int i = 2; i <= x; i++){
        double addOn = 1;
        for(int j = 0; j < i; j++){
            addOn += ev[j] * dp[n][i - j];
            //cout << ev[j] << " " << dp[n][i - j] << "\n";
        }
        //cout << addOn << " " << dp[n][0] << "\n";
        ev[i] = (addOn)/(1 - dp[n][0]);
    }
    cout << fixed << setprecision(15);
    cout << ev[x] << "\n";
}