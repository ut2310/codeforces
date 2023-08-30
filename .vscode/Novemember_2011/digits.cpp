/*
USER: ut23101
LANG: C++14
TASK: concom
*/
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
long long int convert_to_base_10(int base, string input)
{
    long long int res = 0;
    for(int i = 0; i < input.size(); i++)
    {
        res += pow(base, i) * ((int) input.at(input.size() - i - 1) - 48);
    }
    return res;
}
string convert_from_base_10(int base, long long int input)
{
    string res = "";
    while(input != 0)
    {
        long long int temp = input % base;
        res = to_string(temp) + res;
        input = input/base;
    }
    return res;
}
bool check(string s1, string s2)
{
    int count = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1.at(i) != s2.at(i))
        {
            count++;
        }
    }
    if(count == 1)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("digits.in", "r", stdin);
	freopen("digits.out", "w", stdout);
    string base2, base3;
    cin >> base2 >> base3;
    for(int i = 0; i < base2.size(); i++)
    {
        string temp;
        if(base2.at(i) == 1)
        {
            temp = base2.substr(0, i) + "0" + base2.substr(i + 1, base2.size());
        }
        else
        {
            temp = base2.substr(0, i) + "1" + base2.substr(i + 1, base2.size());
        }
        long long int num = convert_to_base_10(2, temp);
        string s = convert_from_base_10(3, num);
        if(check(s, base3))
        {
            cout << num;
            break;
        }
    }
}
