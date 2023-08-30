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
#define MAXN 200005
int t, N;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        vector<int> a, b;
        map<int, int> pos;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            a.push_back(temp);
            pos.insert(make_pair(temp, i));
        }
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            b.push_back(temp);
        }
        int index = 0;
        int res = 10000000;
        for(int i = 0; i < b.size(); i++)
        {
            while(sorted_a[index] < b[i])
            {
                index++;
                res = min(res, i + pos[sorted_a[index]]);
            }
        }
        cout << res << "\n";
    }
}