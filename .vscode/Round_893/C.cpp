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
#define MAXN 100005
int t, n, visited[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<int> res;
        if(n % 2 == 0)
        {
            for(int j = n; j > n/2; j-= 2)
            {
                res.push_back(j);
                visited[j] = 1;
                int i = j;
                while(i % 2 == 0)
                {
                    res.push_back(i/2);
                    visited[i/2] = 1;
                    i = i/2;
                }
                //cout << i << "\n";
            }
        }
        else
        {
            for(int j = n - 1; j > n/2; j-= 2)
            {
                res.push_back(j);
                visited[j] = 1;
                int i = j;
                while(i % 2 == 0)
                {
                    res.push_back(i/2);
                    visited[i/2] = 1;
                    i = i/2;
                }
                //cout << i << "\n";
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == 0)
            {
                res.push_back(i);
            }
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}