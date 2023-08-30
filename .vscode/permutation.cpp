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
#define MAX_N 1000
int N;
bool visited[MAX_N];
int ar[MAX_N];
void recur(int index)
{
    if(index == N)
    {
        for(int i = 0; i < N; i++)
        {
            cout << ar[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            ar[index] = i + 1;
            recur(index + 1);
            visited[i] = 0;
        }
        
    }
}
int main()
{
    cin >> N;
    int index = 0;
    recur(index);
}
