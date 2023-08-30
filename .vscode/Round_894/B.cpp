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
ll t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<ll> input;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        vector<ll> output;
        output.push_back(input[0]);
        for(int i = 1; i < n; i++)
        {
            if(input[i] >= input[i - 1])
            {
                output.push_back(input[i]);
            }
            else
            {
                output.push_back(input[i]);
                output.push_back(input[i]);
            }
        }
        cout << output.size() << "\n";
        for(int i = 0; i < output.size(); i++)
        {
            cout << output[i] << " ";
        }
        cout << "\n";
    }
}