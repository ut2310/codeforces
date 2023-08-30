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
long long int t, n;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        long long int res = 0;
        while(n > 0)
        {
            res += n;
            n = n/2;
        }
        cout << res << "\n";
    }
}