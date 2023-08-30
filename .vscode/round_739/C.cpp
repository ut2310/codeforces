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
int t, N;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        int low = 0;
        int high = 40000;
        while(low < high)
        {
            int mid = (low + high + 1)/2;
            if(mid * mid < N)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        int start = low * low + 1;
        int end = (low + 1) * (low + 1);
        int middle = (start + end)/2;
        if(N == middle)
        {
            cout << (low + 1) << " " << (low + 1) << "\n";
        }
        else if(N < middle)
        {
            cout << N - low * low << " " << low + 1 << "\n";
        }
        else
        {
            cout << low + 1 << " " << (low + 1) * (low + 1) - N + 1 << "\n";
        }
    }
}