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
int n, m;
int main()
{
    cin >> n >> m;
    vector<int> input;
    for(int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        input.push_back(temp);
    }
    sort(input.begin(), input.end());
    int track = 0;
    int res = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(track >= m)
        {
            break;
        }
        track += input[i];
        res++;
    }
    cout << res;
}