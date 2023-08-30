using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <math.h>
int main()
{
    int T, n;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n;
        long long int res = 0;
        res += n * (n + 1)/2;
        long long int p = (long long int)log2(n);
        long long int temp = (long long int)pow(2, p + 2) - 2;
        res -= temp;
        cout << res << "\n";
    }
}