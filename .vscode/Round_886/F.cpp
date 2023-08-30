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
#define MAXN 200005
long long int t, n, dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        map<long long int, long long int> mp;
        for(int i = 0; i < n; i++)
        {
            long long int temp; cin >> temp;
            mp[temp]++;
        }
        for(auto i: mp)
        {
            for(long long int j = i.first; j <= n; j+=i.first)
            {
                dp[j] += i.second;
            }
        }
        long long int res = 0;
        for(int i = 1; i <= n; i++)
        {
            res = max(res, dp[i]);
            dp[i] = 0;
        }
        cout << res << "\n";
    }
}