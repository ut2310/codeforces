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
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        string s; cin >> s;
        s = "0" + s;
        string res = "";
        int index = -1;
        for(int i = s.size() - 1; i >= 1; i--)
        {
            if(s.at(i) >= '5')
            {
                index = i - 1;
            }
            if(index == i && s.at(i) >= '4')
            {
                index = i - 1;
            }
        }
        if(index != -1)
        {
            for(int i = 0; i < index; i++)
            {
                if(i == 0 && s.at(i) == '0')
                {
                    continue;
                }
                res = res.append(s.substr(i, 1));
            }
            string value = to_string(int(s.at(index) - '0') + 1);
            res = res.append(value);
            for(int i = index + 1; i < s.size(); i++)
            {
                res = res.append("0");
            }
            cout << res << "\n";
        }
        else
        {
            if(s.at(0) == '0')
            {
                cout << s.substr(1) << "\n";
            }
            else
            {
                cout << s << "\n";
            }
        }
    }
}