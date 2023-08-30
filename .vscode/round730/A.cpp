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
int N;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        long long int a, b;
        cin >> a >> b;
        if(a - b == 0)
        {
            cout << "0 0" << "\n";
        }
        else if(a - b > 0)
        {
            cout << a - b << " 0" << "\n";
        }
        else
        {
            cout << "0 " << a - b << "\n";
        }
    }
}