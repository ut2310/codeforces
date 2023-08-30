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
        cin >> N;
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
        {
            if(s.at(i) == 'U')
            {
                cout << 'D';
            }
            else if(s.at(i) == 'D')
            {
                cout << 'U';
            }
            else
            {
                cout << s.at(i);
            }
        }
        cout << "\n";
    }
}