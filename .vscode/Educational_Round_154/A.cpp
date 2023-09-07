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
#define MAXN 200005
#define ll long long
ll t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        string s = to_string(n);
        int i1 = -1;
        int i2 = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s.at(i) == '1')
            {
                i1 = i;
            }
            if(s.at(i) == '3')
            {
                i2 = i;
            }
        }
        if(i2 > i1)
        {
            cout << "13\n";
        }
        else
        {
            cout << "31\n";
        }
    }
}