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
        long long int x = n * (n - 1)/2;
        vector<long long int> input;
        for(int i = 0; i < x; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        sort(input.begin(), input.end());
        vector<long long int> res;
        int track = 0;
        for(int i = 0; i < n - 1; i++)
        {
            res.push_back(input[track]);
            track += (n - 1 - i);
        }
        res.push_back(1e9);
        for(int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}