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
int t;
int main()
{
    cin >> t;
    while(t-->0)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int total = a * b/2;
        if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
        {
            cout << "YES\n";
        }
        else if(a % 2 == 0 && b % 2 == 1 && total - c >= a/2 && (total - c - a/2) % 2 == 0)
        {
            cout << "YES\n";
        }
        else if(b % 2 == 0 && a % 2 == 1 && c>=b/2 && (c - b/2) % 2 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}