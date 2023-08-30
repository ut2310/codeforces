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
ll t, n, arr[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<ll> input;
        bool flag = true;
        ll track = 0;
        ll prev = -1;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            if(temp > n)
            {
                flag = false;
            }
            input.push_back(temp);
            
        }
        if(!flag)
        {
            cout << "NO\n";
        }
        else
        {
            ll prev = input[0];
            track = 1;
            arr[prev] = 1;
            for(int i = 1; i < n; i++)
            {
                track++;
                if(input[i] == prev)
                {
                    arr[prev] = track;
                }
                else
                {
                    for(int j = prev - 1; j > input[i]; j--)
                    {
                        arr[j] = arr[j + 1];
                    }
                    arr[input[i]] = track;
                }
                prev = input[i];
            }
            for(int i = prev - 1; i >= 1; i--)
            {
                arr[i] = arr[i + 1];
            }
            for(int i = 1; i <= n; i++)
            {
                //cout << arr[i] << " " << input[i - 1] << "\n";
                if(arr[i] != input[i - 1])
                {
                    flag = false;
                }
                arr[i] = 0;
            }
            if(!flag)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
}