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
#define MAXN 100005
int t, N;
string s1, s2;
int visited[MAXN];
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> N >> s1 >> s2;
        vector<pair<int, int>> input;
        for(int i = 0; i < N; i++)
        {
            input.push_back(make_pair(stoi(s1.substr(i, 1)), stoi(s2.substr(i, 1))));
        }
        int res = 0;
        for(int i = 0; i < N; i++)
        {
            if(input[i].first != input[i].second)
            {
                res += 2;
                visited[i] = 1;
            }
            else
            {
                if(input[i].first == 1)
                {
                    if(i >= 1)
                    {
                        if(visited[i - 1] == 0 && input[i - 1].first == 0)
                        {
                            res += 2;
                            visited[i - 1] = 1;
                            visited[i] = 1;
                        }
                    }
                }
                else
                {
                    if(i >= 1)
                    {
                        if(visited[i - 1] == 0 && input[i - 1].first == 1)
                        {
                            res += 2;
                            visited[i - 1] = 1;
                            visited[i] = 1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(visited[i] == 0 && input[i].first == 0)
            {
                res += 1;
            }
            visited[i] = 0;
        }
        cout << res << "\n";
    }
}