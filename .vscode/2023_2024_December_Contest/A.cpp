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
ll t, n, x, y;
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> x >> y >> n;
        if(y - x < (n * (n - 1)/2))
        {
            cout << "-1\n";
        }
        else
        {
            ll z = (n - 1) * (n - 2)/2;
            ll res = y - x - z + x;
            cout << x << " ";
            cout << (res) << " ";
            for(int i = 0; i < n - 2; i++)
            {
                res += (n - 2 - i);
                cout << res << " ";
            }
            cout << "\n";
        }
    }
}