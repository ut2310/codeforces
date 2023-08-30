/*
USER: ut23101
LANG: C++17
TASK: loan
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
long long int N, K, M; // N - total gallons, K days, M - minimum # of gallons of milk everyday
bool check(long long int X)
{
    long long int days = 0;
    while(N/X > M)
    {
        if(N/X >= X)
        {
            N -= N/X;
            days += 1;
        }
        else
        {
            long long int goal = N/X * X - 1;
            long long int incre = N/X;
            // upper division - (N - goal), lower division - increments
            days += (N - goal + incre - 1)/incre;
            N -= (N - goal + incre - 1)/incre * incre;
        }
    }   
    days += (N + M - 1)/M;
    if(days <= K)
    {
        return true;
    }
    return false;
}   
int main()
{
    freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
    cin >> N >> K >> M;
    long long int low = 1;
    long long int high = N;
    long long int temp = N;
    while(low < high)
    {
        N = temp;
        long long int mid = (low + high + 1)/2;
        if(check(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << low;
}
//End: 11:45