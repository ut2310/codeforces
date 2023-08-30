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
long long int t, N;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        vector<long long int> input;
        for(int i = 0; i < N; i++)
        {
            long long int temp; cin >> temp;
            input.push_back(temp);
        }
        vector<long long int> store;
        for(int i = 0; i < N/2; i++)
        {
            store.push_back(abs(input[i] - input[N - 1 - i]));
        }
        bool flag = true;
        for(int i = 0; i < store.size(); i++)
        {
            if(store[i] != 0)
            {
                flag = false;
            }
        }
        if(flag)
        {
            cout << 0 <<"\n";
        }
        else
        {
            long long int res = store[0];
            for(int i = 0; i < store.size(); i++)
            {
                res = gcd(res, store[i]);
            }
            cout << res << "\n";
        }
    }
}