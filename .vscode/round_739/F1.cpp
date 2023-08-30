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
int t, N, a;
bool valid(string temp, char compare)
{
    for(int i = 1; i < temp.size(); i++)
    {
        if(temp.at(i) == compare)
        {
            continue;
        }
        else if(temp.at(i) < compare)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N >> a;
        string str = to_string(N);
        if(a == 1)
        {
            if(str.length() >= 2)
            {
                string res = "";
                if(valid(str, str.at(0)))
                {
                    for(int i = 0; i < str.length(); i++)
                    {
                        res = res + str.substr(0, 1);
                    }
                }
                else
                {
                    char new_c = str.at(0) + 1;
                    for(int i = 0; i < str.length(); i++)
                    {
                        res = res + new_c;
                    }
                }
                cout << res << "\n";
            }
            else
            {
                cout << N << "\n";
            }
        }
        else
        {
            if(str.length() >= 3)
            {
                string res = str.substr(0, 1);
                char compare = max(str.at(0), str.at(1));
                if(valid(str, compare))
                {
                    char other = min(str.at(0), str.at(1));
                    bool flag = false;
                    for(int i = 1; i < str.length(); i++)
                    {
                        if(str.at(i) < compare && !flag)
                        {
                            flag = true;

                        }
                        
                    }
                }
                else
                {
                    char new_c = str.at(1) + 1;
                        
                    for(int i = 2; i < str.size(); i++)
                    {
                        
                    }
                }
            }
            else
            {
                cout << N << "\n";
            }
        }
    }
}