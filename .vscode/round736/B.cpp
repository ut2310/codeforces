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
#define MAXN 200005
int Q, N;
string s1, s2;
int visited[MAXN];
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        cin >> N >> s1 >> s2;
        int counter = 0;
        for(int i = 0; i < N; i++)
        {
            if(s2.at(i) == '1')
            {
                if(s1.at(i) == '0')
                {
                    counter++;
                    continue;
                }
                if(i != 0)
                {
                    if(s1.at(i - 1) == '1' && visited[i - 1] == 0)
                    {
                        counter++;
                        visited[i - 1] = 1;
                        continue;
                    }
                }
                if(i != N - 1)
                {
                    if(s1.at(i + 1) == '1' && visited[i + 1] == 0)
                    {
                        counter++;
                        visited[i + 1] = 1;
                        continue;
                    }
                }
            }
        }
        cout << counter << "\n";

    }
}