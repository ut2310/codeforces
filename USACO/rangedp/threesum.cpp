using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5000
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
int num[MAXN][MAXN];
ll dp[MAXN][MAXN];
int main()
{
    freopen("threesum.in","r",stdin);
    freopen("threesum.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> visited(2e6 + 5);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll need = -(a[i] + a[j]);
            if(need > 1e6 || need < -1e6){
                num[i][j] += num[i][j - 1];
                visited[a[j] + 1e6]++;
                continue;
            }
            num[i][j] += visited[need + 1e6] + num[i][j - 1];
            visited[a[j] + 1e6]++;
        }
        for(int j = i + 1; j < n; j++){
            visited[a[j] + 1e6]--;
        }
    }
    for(int i = 3; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            //look at j to j + i - 1
            dp[j][j + i - 1] += dp[j + 1][j + i - 1] + num[j][j + i - 1];
        }
    }
    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r; l--; r--;
        cout << dp[l][r] << "\n";
    }
}