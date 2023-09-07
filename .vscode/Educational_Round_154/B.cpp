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
#define MAXN 200005
#define ll long long
ll t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        string s; cin >> s;
        string q; cin >> q;
        vector<int> check1;
        vector<int> check2;
        for(int i = 1; i < s.size() - 1; i++)
        {
            if(s.at(i) == '0' && s.at(i + 1) == '1')
            {
                check1.push_back(i + 1);
            }
            if(s.at(i) == '1' && s.at(i - 1) == '0')
            {
                check1.push_back(i);
            }
        }
        for(int i = 1; i < q.size() - 1; i++)
        {
            if(q.at(i) == '0' && q.at(i + 1) == '1')
            {
                check2.push_back(i + 1);
            }
            if(q.at(i) == '1' && q.at(i - 1) == '0')
            {
                check2.push_back(i);
            }
        }
        bool flag = false;
        for(int i = 0; i < check1.size(); i++)
        {
            for(int j = 0; j < check2.size(); j++)
            {
                if(check1[i] == check2[j])
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag || s == q)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}