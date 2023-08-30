using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
using namespace std;
int t, a, b;
int main()
{
    cin >> t; 
    while(t-->0)
    {
        cin >> a >> b;
        if(gcd(a, b) == 1)
        {
            cout << "1\n";
            cout << a << " " << b << "\n";
        }
        else
        {
            cout << "2\n";
            cout << a - 1 << " " << a << "\n";
            cout << a << " " << b << "\n"; 
        }
    }

}