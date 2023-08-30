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
int T, N;
vector<int> parity;
int main()
{
    cin >> T;
    while(T-->0)
    {
        cin >> N;
        int counte = 0;
        int counto = 0;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            parity.push_back(temp % 2);
            if(temp % 2 == 0)
            {
                counte++;
            }
            else
            {
                counto++;
            }
        }
        if(abs(counte - counto) >= 2)
        {
            cout << "-1\n";
        }
        else
        {
            
        }
    }
}