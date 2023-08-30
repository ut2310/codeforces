#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    vector<pair<int, int>> intervals;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        intervals.push_back(make_pair(a, b));
    }
    vector<long long int> sum_counts(2 * M + 1, 0);
    vector<long long int> end_sum_counts(2 * M + 1, 0);
    vector<int> freqa(M + 1, 0);
    vector<int> freqb(M + 1, 0);
    for(int i = 0; i < N; i++)
    {
        freqa[intervals[i].first]++;
    }
    for(int i = 0; i < N; i++)
    {
        freqb[intervals[i].second]++;
    }   
    for(int i = 0; i <= M; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            sum_counts[i + j] += 1ll * freqa[i] * freqa[j];
        }
    }
    for(int i = 0; i <= M; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            end_sum_counts[i + j] += 1ll * freqb[i] * freqb[j];
        }
    }
    /*
    1 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 4 4 7 7 7
    */
    long long int res = 0;
    for(int i = 0; i < 2 * M + 1; i++)
    {
        res += sum_counts[i];
        cout << res << "\n";
        res -= end_sum_counts[i];
    }
    /*
    vector<long long int> ps_sum_counts(2 * M  + 1, 0);
    vector<long long int> ps_end_sum_counts(2 * M + 2, 0);
    ps_sum_counts[0] = sum_counts[0];
    for(int i = 1; i <= 2 * M; i++)
    {
        ps_sum_counts[i] = sum_counts[i] + ps_sum_counts[i - 1];
    }
    for(int i = 1; i <= 2 * M + 1; i++)
    {
        ps_end_sum_counts[i] = ps_end_sum_counts[i - 1] + end_sum_counts[i - 1];
    }
    for(int i = 0; i <= 2 * M; i++)
    {
        long long int res = ps_sum_counts[i] + ps_end_sum_counts[i];
        cout << res << "\n";
    }
    */
    return 0;
}