    #include <bits/stdc++.h>
    #define ll int
    using namespace std;
    #define MAXN 105
    ll n, m, arr[MAXN][MAXN];
    bool solve(ll i)
    {
        vector<vector<bool>> visited(n, vector<bool>(m));
        visited[0][0] = 1;
        for(int i1 = 1; i1 < m; i1++)
        {
            if(visited[0][i1 - 1] == 1 && arr[0][i1] % i == 0)
            {
                visited[0][i1] = 1;
            }
        }
        for(int i1 = 1; i1 < n; i1++)
        {
            if(visited[i1 - 1][0] == 1 && arr[i1][0] % i == 0)
            {
                visited[i1][0] = 1;
            }
        }
        for(int i1 = 1; i1 < n; i1++)
        {
            for(int j = 1; j < m; j++)
            {
                if((visited[i1 - 1][j] == 1 || visited[i1][j - 1] == 1) && arr[i1][j] % i == 0)
                {
                    visited[i1][j] = 1;
                }
            }
        }
        if(visited[n - 1][m - 1] == 1) return true;
        return false;
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t; cin >> t;
        while(t-->0)
        {
            cin >> n >> m;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m ; j++)
                {
                    cin >> arr[i][j];
                }
            }
            ll res = 1;
            ll best = __gcd(arr[0][0], arr[n - 1][m - 1]);
            for(ll i = 1; i * i <= best; i++)
            {
                if(best % i == 0)
                {
                    bool flag1 = solve(i);
                    bool flag2 = solve(best/i);
                    if(flag1) res = max(res, i);
                    if(flag2) res = max(res, best/i);
                }
            }
            cout << res << "\n";
        }
    }