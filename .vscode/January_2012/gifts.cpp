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

int N;
long long int total;
bool comp(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
    if(a.first + a.second != b.first + b.second)
    {
        return a.first + a.second < b.first + b.second;
    }
    else
    {
        return a.first < b.first;
    }
}
int main()
{
    freopen("gifts.in", "r", stdin);
	freopen("gifts.out", "w", stdout);
    cin >> N >> total;
    vector<pair<long long int, long long int>> gifts;
    for(int i = 0; i < N; i++)
    {
        long long int a, b;
        cin >> a >> b;
        gifts.push_back(make_pair(a, b));
    }
    sort(gifts.begin(), gifts.end(), comp);
    long long int curr = 0;
    int index = 0;
    int max_index = -1;
    int maxi = 0;
    while(curr <= total && index < N)
    {
        curr += gifts[index].first + gifts[index].second;
        if(gifts[index].first > maxi)
        {
            maxi = gifts[index].first;
            max_index = index;
        }
        index++;
    }
    curr -= gifts[max_index].first/2;
    if(curr > total)
    {
        cout << index - 1;
    }
    else
    {
        cout << index;
    }
}