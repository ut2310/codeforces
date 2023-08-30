using namespace std;
#include <iostream>
#include <math.h>
int main()
{
    long long int Q, left, right;
    cin >> Q;
    for(int x = 0; x < Q; x++)
    {
        cin >> left >> right;
        long long int res = 0;
        for(int i = 0; i <= 9; i++)
        {
            long long int temp = pow(10.0, i);
            res += right/temp - left/temp;
        }
        cout << res << "\n";
    }
}
