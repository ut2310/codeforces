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
bool flag = false;
void check(long long int N, long long int a, long long int b, long long int current)
{
    if(current > N)
    {
        return;
    }
    else if(current == N)
    {
        flag = true;
        return;
    }
    else
    {
        check(N, a, b, current * a);
        check(N, a, b, current + b);
    }
}
int main()
{
    long long int T, N, a, b;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N >> a >> b;
        flag = false;
        check(N, a, b, 1);
        if(flag)
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
        
    }
}