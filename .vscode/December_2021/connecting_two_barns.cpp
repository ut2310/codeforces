/*
USER: ut23101
LANG: C++17
TASK: closest_cow
*/
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
using namespace std;
int T, N, M;
vector<int> adj[MAXN];
int cc[MAXN];
void recur(int vertice, int component)
{
    cc[vertice] = component;
    for(int a: adj[vertice])
    {
        if(cc[a] == 0)
        {
            recur(a, component);
        }
    }
}
int main()
{
    cin >> T;
    while(T-->0)
    {
        cin >> N >> M;
        for(int i = 0; i < M; i++)
        {
            int a, b; 
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int count = 1;
        for(int i = 1; i <= N; i++)
        {
            if(cc[i] == 0)
            {
                recur(i, count);
                count++;
            }
        }
        //cout << "HELLO1\n";
        int number = count - 1; 
        vector<int> comptovert[count];
        for(int i = 1; i <= N; i++)
        {
            comptovert[cc[i]].push_back(i);
        }
        vector<long long int> src(count, 1e9);
        vector<long long int> dst(count, 1e9);
        //cout << "HELLO2\n";
        for(int i = 1; i <= N; i++)
        {
            for(int j: comptovert[cc[1]])
            {
                src[cc[i]] = min(src[cc[i]], (long long)(abs(i - j)));
            }
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j: comptovert[cc[N]])
            {
                dst[cc[i]] = min(dst[cc[i]], (long long)(abs(i - j)));
            }
        }
        //cout << "HELLO3\n";
        long long ans = 1e18;
        for(int i = 1; i <= number; i++)
        {
            ans = min(ans, src[i] * src[i] + dst[i] * dst[i]);
        }
        cout << ans << "\n";
        fill(cc, cc + N + 1, 0);
        for(int i = 0; i < N + 1; i++)
        {
            adj[i].clear();
        }
        
    }
}