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
int t, n, m, k;
int main()
{  
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m >> k;
        vector<pair<int, int>> input;
        for(int i = 0; i <= k; i++)
        {
            int a, b; cin >> a >> b;
            input.push_back(make_pair(a, b));
        }
        bool flag = true;
        for(int i = 1; i <= k; i++)
        {
            if((abs(input[i].first - input[0].first) + abs(input[i].second - input[0].second)) % 2 == 0)
            {
                flag = false;
            }
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