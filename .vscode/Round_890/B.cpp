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
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        int n; cin >> n;
        bool flag = true;

        long long int d = 0;
        long long int res = 0;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            if(temp == 1)
            {
                res += 2;
            }
            else
            {
                res += 1;
            }
            d += temp;
        }
        if(res - d > 0 || n == 1)
        {
            flag = false;
        }
        
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}