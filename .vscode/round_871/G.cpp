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
#define ll long long 
#define MAXN 1000005
long long int t, n;
long long int dp[MAXN];
int main()
{
    cin >> t;
    dp[1] = 1;
    dp[2] = 5;
    long long int k = 2;
    for(long long int i = 3; i <= 1000004; i++)
    {
        if(i == k * (k + 1)/2)
        {
            dp[i] = i * i + dp[i - k];
            k+=1; i+=1;
            dp[i] = dp[i - k + 1] + i * i;
        }
        else
        {
            dp[i] = i * i + dp[i - k] + dp[i - k + 1] - dp[i - (2 * k - 2)];
        }
    }
    while(t-->0)
    {
        cin >> n;
        long long int res = dp[n];
        cout << res << "\n";
    }
}