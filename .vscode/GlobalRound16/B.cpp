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
int t;
int main()
{
    cin >> t;
    while(t-->0)
    {
        string s;
        cin >> s;
        int res = 2;
        bool flag = false;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s.at(i) == '0')
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            res = 0;
        }
        else
        {
            int prev = -1;
            for(int i = 0; i < s.size(); i++)
            {
                if(s.at(i) == '0' && prev == -1)
                {
                    prev = 0;
                    cnt++;
                }
                else if(prev == 0 && s.at(i) != '0')
                {
                    prev = -1;
                }
            }
            if(cnt == 1)
            {
                res = 1;
            }
        }
        cout << res << "\n";
    }
}