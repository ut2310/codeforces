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
int N;
vector<vector<int>> combinations;
void display(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
void recur(vector<int> v, int index, vector<int> current)
{
    
    if(index == N)
    {
        combinations.push_back(current);
        return;
    }
    recur(v, index + 1, current);
    current.push_back(v[index]);
    recur(v, index + 1, current);
}
int main()
{
    cin >> N;
    vector<int> v;
    for(int i = 1; i <= N; i++)
    {
        v.push_back(i);
    }
    vector<int> temp;
    recur(v, 0, temp);
    for(int i = 0; i < combinations.size(); i++)
    {
        display(combinations[i]);
    }
}