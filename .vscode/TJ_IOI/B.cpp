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

long long int maxSubArraySum(vector<long long int> a)
{
   long long int max_so_far = a[0];
   long long int curr_max = a[0];
 
   for (int i = 1; i < a.size(); i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
int N;
int main()
{
    cin >> N;
    vector<long long int> arr;
    for(int i = 0; i < N; i++)
    {
        long long int temp; cin >> temp;
        arr.push_back(temp);
    }
    vector<long long int> first;
    vector<long long int> second;
    for(int i = 1; i < N; i++)
    {
        if(i % 2 == 1)
        {
            first.push_back(arr[i - 1] - arr[i]);
        }
        else
        {
            second.push_back(arr[i - 1] - arr[i]);
        }
    }
    long long int res = 0;
    if(N != 2)
    {
        res = max(maxSubArraySum(first), maxSubArraySum(second));
    }
    else
    {
        res = arr[0] - arr[1];
    }
    cout << res;
}
