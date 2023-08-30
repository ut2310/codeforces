using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
int main()
{
    int Q, N;
    vector<int> input;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> N;
        long long int res = 0;
        for(int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            res += temp;
        }
        if(res/(double)(N) < 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            long long int ans = res - N;
            cout << ans << "\n";
        }
    }
}
