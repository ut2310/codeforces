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
string input;
#define MAX_N 200005
long long int a[MAX_N];
long long int b[MAX_N];
int N, M;
int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        long long int temp;
        cin >> temp;
        a[i] = temp;
    }
    for(int i = 0; i < M; i++)
    {
        long long int temp;
        cin >> temp;
        b[i] = temp;
    }
    sort(a, a + N);

    for(int i = 0; i < M; i++)
    {
        int low = 0;
        int high = N; 
        while(low < high)
        {
            int mid = (low + high + 1)/2;
            if(a[mid] > b[i])
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        if(b[i] >= a[low])
        {
            cout << low + 1 << " ";
        }
        else
        {
            cout << low << " ";
        }
    }
}