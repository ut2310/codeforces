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
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        int max = 0;
        while(a != 0)
        {
            if(a % 10 > max)
            {
                max = a % 10;
            }
            a/= 10;
        }
    }
}