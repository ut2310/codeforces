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
int arr[26];
int main()
{
    int t;
    while(t-->0)
    {
       string s;
       int output = 0;
       int count = 0;
       cin >> s;
       for(int i = 0; i < s.size(); i++)
       {
           arr[(int)(s.at(i)) - 97]++;
       } 
       for(int i = 0; i < 26; i++)
       {
           if(arr[i] > 1)
           {
               output++;
           }
           else if(arr[i] == 1)
           {
               count++;
           }
       }
       output += count/2;
    }
}