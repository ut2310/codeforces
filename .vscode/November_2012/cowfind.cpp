/*
USER: ut23101
LANG: C++17
TASK: cowfind
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
string s;
void print(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int bs(int a, vector<int> b)
{
    int low = 0;
    int high = b.size();
    while(low < high)
    {
        int mid = (low + high)/2;
        if(a < b[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    freopen("cowfind.in", "r", stdin);
	freopen("cowfind.out", "w", stdout);
    vector<int> l, r;
    cin >> s;
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s.substr(i, 2).compare("((") == 0)
        {
            l.push_back(i);
        }
        if(s.substr(i, 2).compare("))") == 0)
        {
            r.push_back(i);
        }
    }
    long long int res = 0;
    for(int i = 0; i < l.size(); i++)
    {
        int index = bs(l[i], r);
        res += (r.size() - index);
    }
    cout << res;
}