using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#define MAXN 11
long long int n, m;
long long int cnt[MAXN];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        long long int temp; cin >> temp;
        cnt[temp]++;
    }
    long long int res = n * (n - 1)/2;
    for(int i = 1; i <= m; i++)
    {
        if(cnt[i] >= 2)
        {
            res -= cnt[i] * (cnt[i] - 1)/2;
        }
    }
    cout << res;
}