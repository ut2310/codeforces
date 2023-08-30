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
        vector<long long int> mountains;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            mountains.push_back(temp);
        }
        sort(mountains.begin(), mountains.end());
        if(mountains.size() == 2)
        {
            cout << mountains[0] << " " << mountains[1] << "\n";
            continue;
        }
        int min_index = 0;
        long long int min_diff = 100000000000000;
        for(int i = 1; i < mountains.size(); i++)
        {
            if(mountains[i] - mountains[i - 1] < min_diff)
            {
                min_index = i;
                min_diff = mountains[i] - mountains[i - 1];
            }
        }
        cout << mountains[min_index] << " ";
        for(int i = min_index + 1; i < mountains.size(); i++)
        {
            cout << mountains[i] << " ";
        }
        for(int i = 0; i < min_index; i++)
        {
            cout << mountains[i] << " ";
        }
        cout << "\n";
    }
}