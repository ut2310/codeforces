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
#define MAXN 45
bool comp(char a, char b)
{
    return a < b;
}
int main()
{
    string s;
    int Q;
    while(Q-->0)
    {
        cin >> s;
        vector<char> v;
        for(int i = 0; i < s.size(); i++)
        {
            v.push_back(s.at(i));
        }
        sort(v.begin(), v.end());
        int counter = v.size();
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == s.at(i))
            {
                counter--;
            }
        }
        cout << counter << "\n";
    }
}