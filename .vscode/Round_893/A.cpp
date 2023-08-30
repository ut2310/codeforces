using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#define ll long long
ll t, a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> a >> b >> c;
        if(a > b)
        {
            cout << "First\n";
        }
        else if(a == b && (a + b + c) % 2 == 0)
        {
            cout << "Second\n";
        }
        else if(a == b && (a + b + c) % 2 == 1)
        {
            cout << "First\n";
        }
        else
        {
            cout << "Second\n";
        }

    }
}