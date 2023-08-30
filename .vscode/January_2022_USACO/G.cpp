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
int Q;
int main()
{
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int N; cin >> N;
        vector<int> input;
        int target = 0;
        for(int j = 0; j < N; j++)
        {
            int temp; cin >> temp;
            if(temp == 2)
            {
                target++;
            }
            input.push_back(temp);
        }
        int ans = 0;
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < j; k++)
            {
                if(input[j] - input[k] == 2 || input[k] - input[j] == 2)
                {
                    ans++;
                }
            }
        }
        ans = ans * target;
        cout << ans << "\n";
    }
}