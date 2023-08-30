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
int Q, n, m;
set<int> vul;
vector<int> adj[MAXN];
void delete_node(int a, int b)
{
    adj[a].
}
void add_node(int a, int b)
{
    if(a < b)
    {
        vul.insert(a);
        if(vul.count(b) > 0)
        { 
            vul.erase(b);
        }
    }
    else
    {
        vul.insert(b);
        if(vul.count(a) > 0)
        { 
            vul.erase(a);
        }
    }
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int main()
{
    cin >> n >> m;
    while(m-->0)
    {
        int a, b; cin >> a >> b;
        
    }
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int temp; cin >> temp;
        if(temp == 1)
        {
            int a, b; cin >> a >> b;
            add_node(a, b);
        }
        if(temp == 2)
        {
            int a, b; cin >> a >> b;
            delete_node(a, b);
        }
    }
}