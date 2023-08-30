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
    cin >> Q;
    for(int x = 0; x < Q; x++)
    {
        cin >> N;
        vector<long long int> weights;
        vector<long long int> subtract;
        subtract.push_back(0);
        for(int i = 0; i < N; i++)
        {
            long long int temp;
            cin >> temp;
            weights.push_back(temp);
        }
        sort(weights.begin(), weights.end());
        if(N == 1 || N == 2)
        {
            cout << 0 << "\n";
        }
        else
        {
            long long int res = weights[weights.size() - 1];
            for(int i = 1; i < weights.size(); i++)
            {
                long long int tempdiff = weights[i] - weights[i - 1];
                subtract[i] = subtract[i - 1] + tempdiff * i;
                res -= subtract[i];
            }
            cout << res << "\n";
        }

    }
}