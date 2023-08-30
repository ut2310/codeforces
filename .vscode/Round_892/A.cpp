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
int t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<int> a;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        int m = a[0];
        vector<int> b;
        vector<int> c;
        b.push_back(m);
        for(int i = 1; i < n; i++)
        {
            if(a[i] == m)
            {
                b.push_back(a[i]);
            }
            else
            {
                c.push_back(a[i]);
            }
        }   
        if(c.size() == 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << b.size() << " " << c.size() << "\n";
            for(int i = 0; i < b.size(); i++)
            {
                cout << b[i] << " ";
            }
            cout << "\n";
            for(int i = 0; i < c.size(); i++)
            {
                cout << c[i] << " ";
            }
            cout << "\n";
        }
    }
}