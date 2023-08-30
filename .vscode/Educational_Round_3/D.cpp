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
#define MAXN 200005
long long int n, m, k, s, a[MAXN], b[MAXN], type[MAXN], cost[MAXN];
vector<pair<long long int, pair<int, int>>> gadgets;
bool valid(int days)
{
    long long int dollarday = 1;
    long long int poundday = 1;
    
    for(long long int i = 1; i < days; i++)
    {
        if(a[i] < a[dollarday - 1])
        {
            dollarday = i + 1;
        }
        if(b[i] < b[poundday - 1])
        {
            poundday = i + 1;
        }
    }
    gadgets.clear();
    for(int i = 0; i < m; i++)
    {
        if(type[i] == 1)
        {
            gadgets.push_back(make_pair(a[dollarday - 1] * cost[i], make_pair(i + 1, dollarday)));
        }
        else
        {
            gadgets.push_back(make_pair(b[poundday - 1] * cost[i], make_pair(i + 1, poundday)));
        }
    }
    sort(gadgets.begin(), gadgets.end());
    long long int sum = 0;
    for(int i = 0; i < k; i++)
    {
        sum += gadgets[i].first;
    }
    if(sum <= s)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m >> k >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    for(int i = 0; i < m; i++)
    {
        cin >> type[i] >> cost[i];
    }
    
    int low = 1;
    int high = n;
    while(low < high)
    {
        int mid = (low + high)/2;   
        bool check = valid(mid);
        if(check)
        {
            high = mid;
        }
        else
        {
            low = mid +  1;
        }
    }
    bool check = valid(low);
    if(!check)
    {
        cout << "-1\n";
    }
    else
    {
        cout << low << "\n";
        for(int i = 0; i < k; i++)
        {
            cout << gadgets[i].second.first << " " << gadgets[i].second.second << "\n";
        }
    }
    
}