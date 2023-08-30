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
    int t;
    cin >> t;
    for(int a = 0; a < t; a++)
    {
        string s;
        cin >> s;
        int res = 10;
        for(int i = 6; i <= 10; i++)
        {
            int counte = 0;
            int counto = 0;
            int counteq = 0;
            int countoq = 0;
            for(int j = 0; j < i; j++)
            {
                if(j % 2 == 0 && s.at(j) == '1')
                {
                    counte++;
                }
                if(j % 2 == 0 && s.at(j) == '?')
                {
                    counteq++;
                }
                if(j % 2 == 1 && s.at(j) == '1')
                {
                    counto++;
                }
                if(j % 2 == 1 && s.at(j) == '?')
                {
                    countoq++;
                }
            }
            if(counte > counto)
            {
                if(i % 2 == 0)
                {
                    if(counte + counteq - counto > (10 - i)/2)
                    {
                        res = i;
                        break;
                    }
                }
                else
                {
                    if(counte + counteq - counto > (10 - i + 1)/2)
                    {
                        res = i;
                        break;
                    }
                }
            }
            else
            {
                if(counto + countoq - counte > (10 - i)/2)
                {
                    res  = i;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}