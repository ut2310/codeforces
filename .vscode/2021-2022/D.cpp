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

int main()
{
    int Q;
    cin >> Q;
    while(Q-->0)
    {
        string s, t;
        bool flag = true;
        cin >> s >> t;
        if(t.size() > s.size())
        {
            flag = false;
        }
        int p1 = s.length() - 1;
        int p2 = t.length() - 1;
        while(p1 >= 0 && p2 >= 0)
        {
            if(s.at(p1) == t.at(p2))
            {
                p1--;
                p2--;
            }
            else
            {
                p1 -= 2;
            }
        }
        if(p2 < 0 && flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}