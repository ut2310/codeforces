using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#define MAXN 5005
int t, n;
vector<int> dp[MAXN];
vector<int> adj[MAXN];
int dfs(int p, int u)
{
    int counter = 0;
    int res = 1;
    for(int v: adj[u])
    {
        if(v != p)
        {
            counter++;
            int temp = dfs(u, v);
            res += temp;
            dp[u].push_back(temp);
        }
    }
    if(counter < 1)
    {
        return 1;
    }
    return res;
}
pair<int, int> findMin(vector<int> arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    bool dp[MAXN][MAXN];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
 
    int diff = 1e9;
 
    for (int j = sum / 2; j >= 0; j--) {
        if (dp[n][j] == true) {
            diff = j;
            break;
        }
    }
    return make_pair(diff, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    t = 1;
    while(t-->0)
    {
        cin >> n;
        long long int res = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int temp; cin >> temp;
            adj[i + 2].push_back(temp);
            adj[temp].push_back(i + 2);
        }
        dfs(1, 1);
        for(int i = 1; i <= n; i++)
        {
            if(dp[i].size() >= 2)
            {
                vector<int> temp = dp[i];
                pair<long long int, long long int> x = findMin(temp, temp.size());
                cout << x.first << " " << x.second << "\n";
                res += x.first * (x.second - x.first);
            }
        }
        cout << res << "\n";
    }
}