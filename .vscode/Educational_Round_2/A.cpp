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
bool check_integer(string s)
{
    bool res = true;
    for(int i = 0; i < s.size(); i++)
    {
        int temp = s.at(i);
        if(temp < 48 || temp > 57)
        {
            res = false;
        }
    }
    if((s.size() > 1 && s.at(0) == '0') || s.size() == 0)
    {
        res = false;
    }
    return res;
}
int main()
{
    string a, b, s;
    cin >> s;
    int prev = -1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s.at(i) == ',' || s.at(i) == ';')
        {
            string temp = s.substr(prev + 1, i - prev - 1);
            if(check_integer(temp))
            {
                a = a + temp + ',';
            }
            else
            {
                b = b + temp + ',';
            }
            prev = i;
        }
    } 
    if(check_integer(s.substr(prev + 1, s.size())))
    {
        a = a + s.substr(prev + 1, s.size()) + ',';
    }
    else
    {
        b = b + s.substr(prev + 1, s.size()) + ','; 
    }
    if(a.size() == 0)
    {
        cout << "-" << "\n";
    }
    else
    {
        cout << "\"" << a.substr(0, a.size() - 1) << "\"\n";
    }
    if(b.size() == 0)
    {
        cout << "-" << "\n";
    }
    else
    {
        cout << "\"" << b.substr(0, b.size() - 1) << "\"\n";
    }
}