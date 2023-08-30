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
        vector<long long int> a;
        vector<long long int> b;
        vector<long long int> diff;
        for(int i = 0; i < n; i++)
        {
            long long int temp; cin >> temp;
            a.push_back(temp);
        }
        for(int i = 0; i < n; i++)
        {
            long long int temp; cin >> temp;
            b.push_back(temp);
        }
        long long int help = -1e10;
        for(int i = 0; i < n; i++)
        {
            diff.push_back(a[i] - b[i]);
            help = max(help, a[i] - b[i]);
        }
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(diff[i] == help)
            {
                res.push_back(i + 1);
            }
        }
        cout << res.size() << "\n";
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}