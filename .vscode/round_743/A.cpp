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
string s;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N >> s;
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s.at(i) != '0')
            {
                res += stoi(s.substr(i, 1));
                if(i != s.size() - 1)
                {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
}