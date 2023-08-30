/*
USER: ut23101
LANG: C++17
TASK: greetings
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

int B, E, arr1[1000005], arr2[1000005];
int main()
{
    freopen("greetings.in", "r", stdin);
	freopen("greetings.out", "w", stdout);
    cin >> B >> E;
    vector<pair<char, int>> Bessie, Elsie;
    for(int i = 0; i < B; i++)
    {
        char c; int temp;
        cin >> temp >> c;
        Bessie.push_back(make_pair(c, temp));
    }
    for(int i = 0; i < E; i++)
    {
        char c; int temp;
        cin >> temp >> c;
        Elsie.push_back(make_pair(c, temp));
    }
    int t1 = 1;
    int pos = 0;
    for(int i = 0; i < B; i++)
    {
        for(int j = 0; j < Bessie[i].second; j++)
        {
            if(Bessie[i].first == 'L')
            {
                pos--;
            }
            else
            {
                pos++;
            }
            arr1[t1] = pos;
            t1++;
        }
    }
    int maxt1 = t1 - 1;
    t1 = 1;
    pos = 0;
    for(int i = 0; i < E; i++)
    {
        for(int j = 0; j < Elsie[i].second; j++)
        {
            if(Elsie[i].first == 'L')
            {
                pos--;
            }
            else
            {
                pos++;
            }
            arr2[t1] = pos;
            t1++;
        }
    }
    int maxt2 = t1 - 1;
    int res = 0;
    bool flag = false;
    for(int i = 1; i <= min(maxt1, maxt2); i++)
    {
        if(arr1[i] == arr2[i] && !flag)
        {
            flag = true;
            //cout << i << " ";
            res++;
        }
        if(arr1[i] != arr2[i])
        {
            flag = false;
        }
    }
    if(maxt1 > maxt2)
    {
        for(int i = maxt2 + 1; i <= maxt1; i++)
        {
            if(arr2[maxt2] == arr1[i])
            {
                res++;
                //cout << i << " ";
            }
        }
    }
    if(maxt2 > maxt1)
    {
       for(int i = maxt1 + 1; i <= maxt2; i++)
        {
            if(arr1[maxt1] == arr2[i])
            {
                res++;
                //cout << i << " ";
            }
        } 
    }
    cout << res;
}
//Start: 10:49 
//Got 8 testcases by 11:09
