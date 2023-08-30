/*
USER: ut23101
LANG: C++17
TASK: berries
*/
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
int N, K;
int main()
{
    freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
    cin >> N >> K;
    vector<int> input;
    int most = 0;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        input.push_back(temp);
        most = max(most, temp);
    }
    sort(input.begin(), input.end());
    int res = 0;
    for(int i = 1; i <= most; i++)
    {
        int buckets = 0;
        int total = 0;
        vector<int> rem;
        for(int j = 0; j < input.size(); j++)
        {
            buckets += input[j]/i;
            rem.push_back(input[j] % i);
        }
        
        if(buckets < K/2)
        {
            break;
        }
        if(buckets >= K)
        {
            total = i * K/2;
            continue;
        }
        else
        {   
            sort(rem.begin(), rem.end());
            total += (buckets - K/2) * i;
            for(int j = 0; j < K - buckets; j++)
            {
                total += rem[rem.size() - j - 1];
            }
        }
        res = max(res, total);
    }
    cout << res << "\n";
    return 0;
}

//Start: 10:17