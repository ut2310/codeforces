#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 100005
ll dp[MAXN][105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n + 1); 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        
    }
    sort(a.begin(), a.end());
    dp[a[1]][1] = 1;
    dp[0][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[0][i] = 1;
        for(int j = 1; j <= 100000; j++)
        {
            if(dp[j][i - 1] == 1) dp[j][i] = 1;
            if(j - a[i] >= 0)
            {
                if(dp[j - a[i]][i - 1] == 1) dp[j][i] = 1;
            }
        
        }
    }
    vector<ll> res;
    for(int i = 1; i <= 100000; i++)
    {
        if(dp[i][n] == 1) res.push_back(i);
    }
    cout << res.size() << "\n";
    for(auto j: res)
    {
        cout << j << " ";
    }
}