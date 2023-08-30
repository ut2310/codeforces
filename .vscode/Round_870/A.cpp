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
long long int t, N;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        vector<int> input;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
        input.push_back(10000000);
        sort(input.begin(), input.end());
        long long int res = 0;

        if(input[N - input[0]] <= input[0])
        {
            res = -1;
        }
        else
        {
            for(int i = 0; i < N; i++)
            {
                if((N - i - 1) == input[i + 1])
                {
                    res = -1;
                    break;
                }
                if(input[i + 1] > (N - i - 2))
                {
                    res = N - (i + 1);
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}