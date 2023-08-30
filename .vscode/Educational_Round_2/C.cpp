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
#define MAXN 100005
string input;
int N;
int arr[26];
char mp[26];
char str[MAXN];
int new_count[26];
int main()
{
    cin >> input;
    for(int i = 0; i < input.size(); i++)
    {
        arr[(int)(input.at(i)) - 97]++;
    }
    N = input.size();
    string letters = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; i++)
    {
        mp[i] = letters.at(i);
    }
    string res = "";
    int total_count = 0;
    int counter = N/2;
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < arr[i]/2; j++)
        {
            str[counter] = mp[i];
            str[N - counter] = mp[i];
            counter--;
            total_count += 2;
        }
        arr[i] = arr[i] % 2;
    }
    for(int i = 0; i < 26; i++)
    {
        if(total_count == input.size())
        {
            break;
        }
        if(arr[i] == 1)
        {
            if(total_count + 1 == input.size())
            {
                string temp1 = res.substr(0, input.size()/2) + mp[i];
                string temp2 = res.substr(input.size()/2);
                res = temp1 + temp2;
                total_count += 1;
            }
            else
            {
                res = mp[i] + res + mp[i];
                total_count += 2;
            }
        }
    }
    
    for(int i = 0; i < res.size(); i++)
    {
        new_count[(int)(res.at(i)) - 97]++;
    }
    res = "";
    int index = -1;
    for(int i = 25; i >= 0; i--)
    {
        for(int j = 0; j < new_count[i]/2; j++)
        {
            res = mp[i] + res + mp[i];
        }
        if(new_count[i] % 2 == 1)
        {
            index = i;
        }
    }
    
    if(index != -1)
    {
        res = res.substr(0, input.size()/2) + mp[index] + res.substr(input.size()/2);
    }
    cout << res;
    
}