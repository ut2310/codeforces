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
#define MAXN 50005
bool comp(pair<vector<int>, int> arr1, pair<vector<int>, int> arr2)
{
    int counter = 0;
    for(int i = 0; i < 5; i++)
    {
        if(arr1.first[i] >= arr2.first[i])
        {
            counter++;
        }
    }
    if(counter >= 3)
    {
        return true;
    }
    return false;
}
int main()
{
    int T, N;
    cin >> T;
    while(T-->0)
    {
        cin >> N;
        vector<pair<vector<int>, int>> input;
        for(int i = 0; i < N; i++)
        {
            vector<int> arr;
            for(int j = 0; j < 5; j++)
            {
                int temp;
                cin >> temp;
                arr.push_back(temp);
            }
            input.push_back(make_pair(arr, i + 1));
        }
        sort(input.begin(), input.end(), comp);
        for(int i = 0; i < input.size(); i++)
        {
            cout << "\n";
            cout << input[i].second << " ";
            for(int j = 0; j < input[i].first.size(); j++)
            {
                cout << input[i].first[j] << " ";
            }
        }
    }
}