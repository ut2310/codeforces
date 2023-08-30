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
        string s; cin >> N >> s;
        bool flag = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s.at(i) == '0')
            {
                if(i < s.size()/2)
                {
                    cout << (i + 1) << " " << s.size() << " " << (i + 2) << " " << s.size(); 
                    flag = true;
                    break;
                }
                else
                {
                    cout << 1 << " " << (i + 1) << " " << 1 << " "<< i;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout << 1 << ' ' << N - 1 << ' ' << 2 << ' ' << N;
        }
        cout << "\n";
    }
}