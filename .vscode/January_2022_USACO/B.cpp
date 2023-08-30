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
        int ans = 0;
        for(int i = 0; i < 81; i++)
        {
            int x; cin >> x;
            if(x == 0)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}