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
int Q, N;
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int res = 0;
        if (a < b)
        {
            res++;
        }
        if(a < c)
        {
            res++;
        }
        if(a < d)
        {
            res++;
        }
        cout << res << "\n";

    }
}