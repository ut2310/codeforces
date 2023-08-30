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
int t, n;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        long long int sum = 0;
        vector<int> input;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            sum += abs(temp);
            if(temp != 0)
            {
                input.push_back(temp);
            }
        }
        int counter = 0;
        bool flag = false;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] < 0)
            {
                if(!flag)
                {
                    flag = true;
                    counter++;
                }
            }
            else
            {
                flag = false;
            }
        }
        cout << sum << " " << counter << "\n";
    }
}