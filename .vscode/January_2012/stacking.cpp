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
int N, K;
int arr[MAXN];
long long int pf[MAXN];
int main()
{
    freopen("stacking.in", "r", stdin);
	freopen("stacking.out", "w", stdout);
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] += 1;
        arr[b + 1] -= 1;
    }
    long long int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += arr[i + 1];
        pf[i] = sum;
    }
    sort(pf, pf + N);
    cout << pf[N/2];
}