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
#define MAXN 101
int t, N;
char s[MAXN];
char flip(char c)
{
    if(c == 'R')
    {
        return 'B';
    }
    return 'R';
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        string temp; cin >> temp;
        for(int i = 0; i < N; i++)
        {
            s[i] = temp.at(i);
        }
        for(int i = 0; i < N; i++)
        {
            if(s[i] != '?')
            {
                int p1 = i - 1;
                while(p1 >= 0 && s[p1] == '?')
                {
                    s[p1] = flip(s[p1 + 1]);
                    p1--;
                }
                int p2 = i + 1;
                while(p2 < N && s[p2] == '?')
                {
                    s[p2] = flip(s[p2 - 1]);
                    p2++;
                }
            }
        }
        if(s[0] == '?')
        {
            s[0] = 'B';
            for(int i = 1; i < N; i++)
            {
                s[i] = flip(s[i - 1]);
            }
        }
        string res = "";
        for(int i = 0; i < N; i++)
        {
            res = res + s[i];
        }
        cout << res;
    }
}