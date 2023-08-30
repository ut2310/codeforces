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

int main()
{
    int N;
    cin >> N;
    for(int t = 0; t < N; t++)
    {
        long long int temp;
        cin >> temp;
        if(temp % 10 == 9)
        {
            cout << (temp/10 + 1) << "\n";
        }
        else
        {
            cout << temp/10 << "\n";
        }
        
    }
}