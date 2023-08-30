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
#define MAXN 1005
int arr[MAXN], N;
int calc(int num)
{
    int count = 0;
    int prev = -1;
    int res = 0;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] != num)
        {
            if(arr[i] == prev)
            {
                count++;
            }
            else if(prev == -1)
            {
                count++;
                prev = arr[i];
            }
            else
            {
                res = max(res, count);
                count = 0;
                prev = -1;
            }
        }
    }
    return res;
}
int main()
{
    cin >> N;
    set<int> numbers;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        numbers.insert(arr[i]);
    }
    int res = 0;
    for(int i: numbers)
    {
        res = max(res, calc(i));
    }
    cout << res << "\n";
}