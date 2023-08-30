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
int Q, N;
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        cin >> N;
        set<int> distinct;
        vector<int> input;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
            distinct.insert(temp);
        }
        int res = 0;
        if(distinct.size() % 2 == N % 2)
        {
            res = distinct.size();
        }
        else
        {
            res = distinct.size() - 1;
        }
        cout << res << "\n";
    }
}