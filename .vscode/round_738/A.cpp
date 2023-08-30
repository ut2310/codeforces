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
int t, N;
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        vector<int> input;
        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            input.push_back(temp);
        }
        int min = 2000000000;
        bool flag = false;
        for(int i = 0; i < N; i++)
        {
            if(isPowerOfTwo(input[i]))
            {
                flag = true;
            }
            if(input[i] < min)
            {
                min = input[i];
            }
        }
        if(flag)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << min << "\n";
        }

    }
}