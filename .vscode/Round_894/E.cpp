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
#define ll long long
ll t, n, m, d;
ll dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m >> d;
        vector<ll> input;
        for(int i = 0; i < n; i++)
        {
            ll x; cin >> x;
            input.push_back(x);
        }
        int counter = 0;
        priority_queue<int> track;
        if(input[0] > 0)
        {
            dp[0] = input[0];
            track.push(-1 * input[0]);
            counter++;
        }

        for(int i = 1; i < n; i++)
        {
            //cout << counter << " " << input[i] << "\n";
            if(input[i] > 0)
            {
                if(counter < m)
                {
                
                    track.push(-1 * input[i]);
                    counter++;
                    dp[i] = dp[i - 1] + input[i];
                }
                else
                {
                    ll value = -1 * track.top();
                    if(input[i] > value)
                    {
                        track.push(-1 * input[i]);
                        track.pop();
                        dp[i] -= value;
                        dp[i] += input[i];
                        dp[i] += dp[i - 1];
                    }
                }
            }
            dp[i] = max(dp[i], dp[i -1]);
        }
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            //cout << dp[i] << " ";
            res = max(res, dp[i] - d * (i + 1));
            dp[i] = 0;
        }
        //cout << "\n";
        cout << res << "\n";

    }
}