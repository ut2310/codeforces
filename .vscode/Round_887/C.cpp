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
#define ll long long 
ll t, n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> k;
        vector<ll> input;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        sort(input.begin(), input.end());
        ll start = 1;
        ll counter = 0;
        ll counter2 = 1;
        map<ll, ll> track;
        for(int i = 1; i < input.size(); i++)
        {
            if(input[i] - input[i - 1] > 1)
            {
                track.insert(make_pair(-1 * counter2, input[i - 1] + 1));
                counter2 += input[i] - input[i - 1] - 1;
            }
        }
        track.insert(make_pair(-1 * counter2, input[input.size() - 1] + 1));
        while(counter < k)
        {
            auto x = track.lower_bound(-1 * start);
            start = start + x->first + x->second;
            counter++;
        }
        if(input[0] != 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << start << "\n";
        }

    }

}