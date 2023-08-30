/*
USER: ut23101
LANG: C++17
TASK: mirrors
*/
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
#define MAXN 205
int N, a, b;
vector<pair<pair<int, int>, char>> mirrors;
int visited[MAXN];
char swi(char temp)
{
   if(temp == '\\')
   {
       return '/';
   }
   return '\\';
}
void change(int index)
{
    mirrors[index] = make_pair(make_pair(mirrors[index].first.first, mirrors[index].first.second), swi(mirrors[index].second));
}
int check(pair<int, int> start, pair<int, int> dir) //finds next mirror index; if no mirror returns -1
{
    int minimum_distance = 1000000000;
    int minimum_mirror = -1;
    for(int i = 0; i < mirrors.size(); i++)
    {
        pair<int, int> distance = make_pair(mirrors[i].first.first - start.first, mirrors[i].first.second - start.second);
        if((dir.first == 0 && distance.first == 0) || (dir.second == 0 && distance.second == 0))
        {
            if(dir.first == 0)
            {
                if(dir.second * distance.second > 0)
                {
                    if(abs(distance.second) < minimum_distance)
                    {
                        minimum_distance = abs(distance.second);
                        minimum_mirror = i;
                    }
                }
            }
            if(dir.second == 0)
            {
                if(dir.first * distance.first > 0)
                {
                    if(abs(distance.first) < minimum_distance)
                    {
                        minimum_distance = abs(distance.first);
                        minimum_mirror = i;
                    }
                }
            }
        }
    }
    return minimum_mirror;
}
pair<int, int> find_new_dir(pair<int, int> dir, int index)
{
    char mir = mirrors[index].second;
    if(mir == '\\')
    {
        if(dir.first == 1 && dir.second == 0)
        {
            return make_pair(0, -1);
        }
        else if(dir.first == -1 && dir.second == 0)
        {
            return make_pair(0, 1);
        }
        else if(dir.first == 0 && dir.second == 1)
        {
            return make_pair(-1, 0);
        }
        else
        {
            return make_pair(1, 0);
        }
    }
    else
    {
        if(dir.first == 1 && dir.second == 0)
        {
            return make_pair(0, 1);
        }
        else if(dir.first == -1 && dir.second == 0)
        {
            return make_pair(0, -1);
        }
        else if(dir.first == 0 && dir.second == 1)
        {
            return make_pair(1, 0);
        }
        else
        {
            return make_pair(-1, 0);
        }
    }
}

int main()
{
    freopen("mirrors.in", "r", stdin);
	freopen("mirrors.out", "w", stdout);
    cin >> N >> a >> b;
    for(int i = 0; i < N; i++)
    {
        int temp1, temp2; char c;
        cin >> temp1 >> temp2 >> c;
        mirrors.push_back(make_pair(make_pair(temp1, temp2), c));
    }
    mirrors.push_back(make_pair(make_pair(a, b), 'a'));
    /*
    for(int i = 0; i < mirrors.size(); i++)
    {
        cout << mirrors[i].first.first << " " << mirrors[i].first.second << " " << mirrors[i].second << "\n";
    }
    */
    
    bool flag = false;
    for(int i = 0; i <= N; i++)
    {
        pair<int, int> current(0, 0);
        pair<int, int> dir(1, 0);
        if(i < N)
        {
            change(i);
        }
        while(true)
        {
            int next_mirror = check(current, dir);
            if(next_mirror == -1)
            {
                break;
            }
            else if(next_mirror == N)
            {
                cout << (i + 1);
                flag = true;
                break;
            }
            else
            {
                visited[next_mirror]++;
                if(visited[next_mirror] == 3)
                {
                    break;
                }
                else
                {
                    current = mirrors[next_mirror].first;
                    dir = find_new_dir(dir, next_mirror);
                }
            }
        }
        if(flag)
        {
            break;
        }
        fill(visited, visited + N + 1, 0);
        if(i < N)
        {
            change(i);
        }
        /*
        for(int i = 0; i < mirrors.size(); i++)
        {
            cout << mirrors[i].first.first << " " << mirrors[i].first.second << " " << mirrors[i].second << "\n";
        }
        */
    }
    if(!flag)
    {
        cout << "-1";
    }
}