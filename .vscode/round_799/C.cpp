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
char arr[8][8];
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        for(int i = 0; i < 8; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < s.size(); j++)
            {
                arr[i][j] = s[j];
            }
        }
        int resx = -1;
        int resy = -1;
        for(int i = 1; i <= 6; i++)
        {
            for(int j = 1; j <= 6; j++)
            {
                if(arr[i - 1][j - 1] == '#' && arr[i - 1][j + 1] == '#' && arr[i + 1][j - 1] == '#' && arr[i + 1][j + 1] == '#')
                {
                    resx = i + 1;
                    resy = j + 1;
                }
            }
        }
        cout << resx << " " << resy << "\n";
    }
}