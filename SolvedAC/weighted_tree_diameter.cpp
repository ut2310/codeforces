using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <math.h>
#include <numeric>
#define MAXN 100005
vector<pair<int, int>> adj[MAXN];
int N, depth[MAXN];
void dfs(int p, int u)
{
    for(auto v: adj[u])
    {
        if(p != v.first)
        {
            depth[v.first] = depth[u] + v.second;
            dfs(u, v.first);
        }
    }
}
int dfs2(int p, int u)
{
    int best = 0;
    for(auto v: adj[u]){
        if(p != v.first){
            int a = dfs2(u, v.first);
            if(a + v.second > best){
                best = a + v.second;
            }
        }
    }
    return best;
}
int main()
{
    cin >> N;
    for(int j = 1; j <= N; j++)
    {
        int i;
        cin >> i;
        int curr, weight; cin >> curr >> weight;
        while(true){
            adj[i].push_back(make_pair(curr, weight));
            cin >> curr;
            if(curr == -1){
                break;
            }
            cin >> weight;
        }
    }   
    depth[1] = 0;
    dfs(1, 1);
    int maxNode = -1;
    int maxDepth = -1;
    for(int i = 1; i <= N; i++)
    {
        if(depth[i] > maxDepth)
        {
            maxNode = i;
            maxDepth = depth[i];
        }
    }
    //cout << maxNode << "\n";
    int res = dfs2(maxNode, maxNode);
    cout << res << "\n";
 
} 