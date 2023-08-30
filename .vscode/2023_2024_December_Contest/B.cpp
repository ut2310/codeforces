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
int t, n, k;
string s;
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> k;
        cin >> s;
        if(k % 2 == 0)
        {
            vector<string> input;
            for(int i = 0; i < s.size(); i++)
            {
                input.push_back(s.substr(i, 1));
            }
            sort(input.begin(), input.end());
            string res = "";
            for(int i = 0; i < s.size(); i++)
            {
                res.append(input[i]);
            }
            cout << res << "\n";
        }
        else
        {
            vector<string> input1;
            vector<string> input2;
            for(int i = 0; i < s.size(); i++)
            {
                if(i % 2 == 0)
                {
                    input1.push_back(s.substr(i, 1));
                }
                else
                {
                    input2.push_back(s.substr(i, 1));
                }
            }
            sort(input1.begin(), input1.end());
            sort(input2.begin(), input2.end());
            string res = "";
            for(int i = 0; i < n; i++)
            {
                if(i % 2 == 0)
                {
                    res.append(input1[i/2]);
                }
                else
                {
                    res.append(input2[i/2]);
                }
            }
            cout << res <<"\n";
        }
    }
}