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
        long long int num;
        cin >> num;
        if(num % 3 == 0)
        {
            cout << num/3 << " " << num/3 << "\n";
        }
        else if(num % 3 == 1)
        {
            cout << num/3 + 1 << " " << num/3 << "\n";
        }
        else
        {
            cout << num/3 << " " << num/3 + 1 << "\n";
        }
    }
}