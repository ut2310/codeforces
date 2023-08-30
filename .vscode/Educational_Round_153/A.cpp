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
#define ll long long 
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        string s; cin >> s;
        int n = s.size();
        if(n == 2 && s == "()")
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            string res1 = "";
            for(int i = 0; i < n; i++)
            {
                res1.append("(");
            }
            for(int i = 0; i < n; i++)
            {
                res1.append(")");
            }
            string res2 = "";
            for(int i = 0; i < n; i++)
            {
                res2.append("()");
            }
            bool flag = true;
            for(int i = 0; i <= n; i++)
            {
                if(s == res1.substr(i, n))
                {
                    flag = false;
                }
            }
            if(flag)
            {
                cout << res1 << "\n";
            }
            else
            {
                cout << res2 << "\n";
            }
        }
    }
}