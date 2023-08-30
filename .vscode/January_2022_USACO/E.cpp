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
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(a % b != 0)
        {
            ans = -1;
        }
        else
        {
            ans = b;
        }
        cout << ans << "\n";
    }
}
