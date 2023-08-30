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
vector<vector<long long int>> combinations;
void display(vector<long long int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
void recur(vector<long long int> v, int index, vector<long long int> current)
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
bool check_carries(vector<long long int> input)
{
    bool res = true;
    long long int sum = 0;
    set<long long int> done;
    while(done.size() < input.size())
    {
        for(int i = 0; i < input.size(); i++)
        {
            sum += input[i] % 10;
            input[i] = input[i]/10;
            if(input[i] == 0)
            {
                done.insert(i);
            }
        }
        if(sum >= 10)
        {
            res = false;
            break;
        }
        sum = 0;
    }
    return res;
}
int main()
{
    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
    cin >> N;
    vector<long long int> v;
    for(int i = 1; i <= N; i++)
    {
        long long int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<long long int> temp;
    recur(v, 0, temp);
    int res = 0;
    for(int i = 0; i < combinations.size(); i++)
    {
        if(combinations[i].size() != 0)
        {
            if(check_carries(combinations[i]))
            {
                if(combinations[i].size() > res)
                {
                    res = combinations[i].size();
                }
            }
        }
    }
    cout << res;
}