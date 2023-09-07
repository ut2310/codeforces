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
ll t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    t = 1;
    while(t-->0)
    {
        cin >> n;
        vector<int> input;
        ll res = 1e10;
        for(int i = 0; i < n; i++)
        {
            ll temp; cin >> temp;
            res = min(res, abs(temp));
        }
        cout << res << "\n";

    }
}