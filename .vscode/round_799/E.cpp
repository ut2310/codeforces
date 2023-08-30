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
#include <unordered_map>
int Q, N, S;
int findMaxLenSubarray(vector<int> nums, int n, int S)
{
    // create an empty map to store the ending index of the first subarray
    // having some sum
    unordered_map<int, int> map;
 
    // insert (0, -1) pair into the set to handle the case when a
    // subarray with sum `S` starts from index 0
    map[0] = -1;
 
    int target = 0;
 
    // `len` stores the maximum length of subarray with sum `S`
    int len = 0;
 
    // stores ending index of the maximum length subarray having sum `S`
    int ending_index = -1;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far
        target += nums[i];
 
        // if the sum is seen for the first time, insert the sum with its
        // into the map
        if (map.find(target) == map.end()) {
            map[target] = i;
        }
 
        // update length and ending index of the maximum length subarray
        // having sum `S`
        if (map.find(target - S) != map.end() && len < i - map[target - S])
        {
            len = i - map[target - S];
            ending_index = i;
        }
    }
    return len;
}
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        cin >> N >> S;
        vector<int> input;
        int total = 0;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            total += temp;
            input.push_back(temp);
        }
        int res = 0;
        if(total < S)
        {
            res = -1;
        }
        else if(S == total)
        {
            res == 0;
        }
        else
        {
            int temp = findMaxLenSubarray(input, N, S);
            res = N - temp;
        }
        cout << res << "\n";
    }
}