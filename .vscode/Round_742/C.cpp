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
        string s;
        cin >> s;
        string s1;
        string s2;
        for(int i = 0; i < s.size(); i++)
        {
            if(i % 2 == 0)
            {
                s1 = s1 + s.at(i);
            }
            else
            {
                s2 = s2 + s.at(i);
            }
        }
        long long int x;
        if(s2.size() != 0)
        {
            x = (stoi(s1) + 1) * (stoi(s2) + 1) - 2;
        }
        else
        {
            x = (stoi(s1) - 1);
        }
        cout << x << "\n";

    }
}