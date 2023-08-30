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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<long long int> input;
        for(int i = 0; i < n; i++)
        {
            long long int temp; cin >> temp;
            input.push_back(temp);
        }
        bool flag = true;
        long long int res = 0;
        for(int i = input.size() - 1; i > 0; i--)
        {
            if(input[i] < input[i - 1])
            {
                res = max(res, input[i - 1]);
            }
        }
        cout << res << "\n";
    }
}