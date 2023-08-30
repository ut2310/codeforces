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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<long long int> input2;
        vector<long long int> input;
        vector<long long int> res;
        long long int sum = 0;
        for(int i = 0; i < n; i++)
        {
            long long int temp; cin >> temp;
            input2.push_back(temp);
            input.push_back(temp);
            sum += temp;
        }
        sort(input.begin(), input.end());
        vector<long long int> suffix;
        suffix.push_back(sum);
        for(int i = 1; i < n; i++)
        {
            suffix.push_back(sum - input[i - 1]);
            sum = sum - input[i - 1];
        }
        long long int track = 0;
        map<long long int, long long int> res2;
        for(int i = 0; i < n; i++)
        {
            long long int quant = input[i] * i - track;
            res.push_back(suffix[i] - ((n - i) * input[i]) + quant + n);
            res2.insert(make_pair(input[i], suffix[i] - ((n - i) * input[i]) + quant + n));
            track += input[i];
        }
        for(int i = 0; i < n; i++)
        {
            cout << (res2[input2[i]]) << " ";
        }
        cout << "\n";
    }
}