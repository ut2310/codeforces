/*
USER: ut23101
LANG: C++17
TASK: typo
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
int main()
{
    freopen("typo.in", "r", stdin);
	freopen("typo.out", "w", stdout);
    cin >> s;
    vector<int> track;
    int counter = 0, res = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s.at(i) == '(')
        {
            counter++;
        }
        else
        {
            counter--;
        }
        track.push_back(counter);
    }
    //print(track);
    if(track[track.size() - 1] == 2)
    {
        int stop = track.size();
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(track[i] < 2)
            {
                stop = i;
                break;
            }
        }
        for(int i = stop + 1; i < s.size(); i++)
        {
            if(s.at(i) == '(')
            {
                res++;
            }
        }
    }
    else
    {
        int stop = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(track[i] < 0)
            {
                stop = i;
                break;
            }
        }
        //cout << stop << "\n";
        for(int i = 0; i <= stop; i++)
        {
            if(s.at(i) == ')')
            {
                res++;
                //cout << i << " " << s.at(i) << "\n";
            }
        }
    }
    cout << res;
}
// Start: 10:48, End: 11:38