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
int t, n;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<int> input;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        sort(input.begin(), input.end());
        long long int res = 0;
        if(input.size() != 1)
        {
            for(int i = 0; i < n/2; i++)
            {
                res -= input[i];
            }
            for(int i = n/2 + 1; i < n; i++)
            {
                res += input[i];
            }
            if(n % 2 == 0)
            {
                res += input[n/2];
            }
        }
        
        cout << res << "\n";
    }
}