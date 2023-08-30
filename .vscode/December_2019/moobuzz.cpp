/*
USER: ut23101
LANG: C++17
TASK: moobuzz
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
int arr[8];
int main()
{
    freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
    int N;
    cin >> N;
    arr[0] = 14;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 7;
    arr[5] = 8;
    arr[6] = 11;
    arr[7] = 13;
    long long int res = 0;
    if(N % 8 == 0)
    {
        res += (N/8) * 15 - 1;
    }
    else
    {
        res += (N/8) * 15 + arr[N % 8];
    }
    cout << res << "\n";
}