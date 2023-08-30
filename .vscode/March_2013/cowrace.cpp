/*
USER: ut23101
LANG: C++17
TASK: cowrace
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
#define MAXN 1000005
int N, M, arr1[MAXN], arr2[MAXN];
int main()
{
    cin >> N >> M;
    vector<pair<int, int>> Bessie;
    vector<pair<int, int>> Elsie;
    int cnt = 1;
    int distance = 0;
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        Bessie.push_back(make_pair(a, b));
        for(int j = cnt; j < cnt + b; j++)
        {
            distance += a;
            arr1[j] = a;
        }
        cnt += b;
    }
    cnt = 0;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        Elsie.push_back(make_pair(a, b));
        for(int j = cnt; j < cnt + b; j++)
        {
            distance += a;
            arr1[j] = a;
        }
        cnt += b;
    }
    
}
//Start: 10:35