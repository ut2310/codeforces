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
ll t, n, m;
char arr[22][22];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            for(int j = 0; j < m; j++)
            {
                arr[i][j] = temp.at(j);
            }
        }
        bool flag = false;
        int i = 0;
        char letter = 'v';
        while(i < m)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[j][i] == letter)
                {
                    if(letter == 'v')
                    {
                        letter = 'i';
                    }
                    else if(letter == 'i')
                    {
                        letter = 'k';
                    }
                    else if(letter == 'k')
                    {
                        letter = 'a';
                    }
                    else
                    {
                        letter = 'z';
                    }
                    break;
                }
            }
            i++;
        }
        if(letter == 'z')
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    
}