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
int main()
{
    cin >> t;
    while(t-->0)
    {
        int a, b;
        cin >> a >> b;
        cout << b/(a/2 + 1) << "\n";
    }
}