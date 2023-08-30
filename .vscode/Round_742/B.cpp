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
int t, a, b;
int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}
bool check(int num, int num2)
{
    int res = computeXOR(num - 1);
    if(res == num2)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> a >> b;
        if(check(a, b))
        {
            cout << a;
        }
        else if(computeXOR(a) == b)
        {
            cout << a + 2;
        }
        else
        {
            cout << a + 1;
        }
        cout << "\n";
    }
}