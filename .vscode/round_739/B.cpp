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
int t, a, b, c;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> a >> b >> c;
        int total = (max(a, b) - min(a, b)) * 2;
        if(total >= a && total >= b && total >= c)
        {
            if(c > total/2)
            {
                cout << c - total/2 << "\n";
            }
            else
            {
                cout << c + total/2 << "\n";
            }
        }
        else
        {
            cout << "-1\n";
        }
        
    }
}