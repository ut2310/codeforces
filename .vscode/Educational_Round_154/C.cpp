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
#include <stack>
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
        string temp; cin >> temp;
        int count1 = 0; //counter # of +
        int count2 = 0;
        int track = 0;
        int prev = -1;
        bool flag = true;
        bool flag2 = false;
        stack<int> s1;
        for(int i = 0; i < temp.size(); i++)
        {
            if(temp.at(i) == '1')
            {
                if(prev == 0)
                {
                    flag = flag2;
                }
                count1 = 0;
                count2 = 0;
                prev = 1;
                flag2 = false;
            }
            else if(temp.at(i) == '-')
            {
                count2++;
                if(prev == 0)
                {
                    if(count2 > count1)
                    {
                        flag2 = true;
                    }
                }
                track--;
            }
            else if(temp.at(i) == '+')
            {
                count1++;
                track++;
            }
            else
            {
                if(track < 2)
                {
                    flag = false;
                }
                if(prev == 1)
                {
                    if(count1 == 0)
                    {
                        flag = false;
                    }
                }
                count1 = 0;
                count2 = 0;
                prev = 0;
                flag2 = false;
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}   