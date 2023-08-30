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
string s;
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        cin >> N >> s;
        bool flag = false;
        for(int i = 0; i < N - 1; i++)
        {
            if(s.at(i) == s.at(i + 1))
            {
                continue;
            }
            else
            {
                flag = true;
                cout << i + 1 << " " << i + 2 << "\n";
                break;
            }
        }
        if(!flag)
        {
            cout << "-1 -1\n";
        }
    }
}