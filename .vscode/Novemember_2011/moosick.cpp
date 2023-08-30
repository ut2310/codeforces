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
int main()
{
    freopen("moosick.in", "r", stdin);
	freopen("moosick.out", "w", stdout);
    int N, C;
    cin >> N;
    vector<int> notes;
    vector<int> sick;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        notes.push_back(temp);
    }
    cin >> C;
    for(int i = 0; i < C; i++)
    {
        int temp;
        cin >> temp;
        sick.push_back(temp);
    }
    sort(sick.begin(), sick.end());
    vector<int> output;
    for(int i = 0; i <= N - C; i++)
    {
        auto first = notes.begin() + i;
        auto last = notes.begin() + i + C;
        vector<int> current(first, last);
        sort(current.begin(), current.end());
        long long int temp = current[0] - sick[0];
        bool flag = true;
        for(int i = 1; i < C; i++)
        {
            if(current[i] - sick[i] != temp)
            {
                flag = false;
            }
        }
        if(flag)
        {
            output.push_back(i + 1);
        }
    }
    cout << output.size() << "\n";
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << "\n";
    }
}