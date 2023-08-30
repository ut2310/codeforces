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
#define MAXN 20005
int N;
int pos[5][MAXN];
int arr[MAXN];
bool comp(int a, int b)
{
    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        if(pos[i][a] < pos[i][b])
        {
            count += 1;
        }
    }
    if(count >= 3)
    {
        return b < a;
    }
    return a < b;
}
int main()
{
    freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            pos[i][temp] = j;
            arr[j] = j + 1;
        }
    }
    sort(arr, arr + N, comp);
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}