using namespace std;
#include <iostream>
int main()
{
    int q;
    long long int n, x, t;
    for(int i = 0; i < q; i++)
    {
        cin >> n >> x >> t;
        long long int res = 0;
        if(n >= x)
        {
            long long int temp = t/x;
            res += temp * (n - x);
            res += temp * (temp - 1)/2;
        }
        else
        {
            res += n * (n - 1)/2;
        }
        cout << res << "\n";
    }
}