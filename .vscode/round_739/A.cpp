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
bool check(int a)
{
    while(a != 0)
    {
        if(a % 10 == 3)
        {
            return false;
        }
        a/=10;
    }
    return true;
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N;
        int counter = 0;
        for(int i = 1; i <= 10000; i++)
        {
            if(i % 3 != 0 && check(i))
            {
                counter++;
            }
            if(counter == N)
            {
                cout << i << "\n";
                break;
            }
        }
    }
}