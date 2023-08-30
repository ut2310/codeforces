/*
USER: ut23101
LANG: C++14
TASK: concom
*/
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
vector<pair<int, int>> *adj = new vector<pair<int, int>>[101];
set<int> find_controlled(int i)
{
    map<int, int> percetage;
    set <int> controlled;
    queue<int> track;
    controlled.insert(i);
    track.push(i);
    while(!track.empty())
    {
        int current = track.front();
        track.pop();
        for(pair<int, int> company: adj[current])
        {
            if(controlled.count(company.first) == 0)
            {
                if(company.second >= 50)
                {
                    controlled.insert(company.first);
                    track.push(company.first);
                }
                else
                {
                    if(percetage.count(company.first) > 0)
                    {
                        if(percetage.at(company.first) + company.second < 50)
                        {
                            percetage.at(company.first) = percetage.at(company.first) + company.second;
                        }
                        else
                        {
                            controlled.insert(company.first);
                            track.push(company.first);
                        }
                    }
                    else
                    {
                        percetage.insert({company.first, company.second});
                    }
                }
            }
        }
    }
    controlled.erase(i);
    return controlled;

}
int main()
{
    /*
    FILE* fp;
    fp = fopen("concom.in", "r");
    vector<pair<pair<int, int>, int>> companies;
    int N;
    scanf(fp, "%i", &N);
    */
    freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        adj[temp1].push_back(make_pair(temp2, temp3));
    }
    for(int i = 1; i <= 100; i++)
    {
        set<int> controlled = find_controlled(i);
        vector<int> output(controlled.begin(), controlled.end());
        sort(output.begin(), output.end());
        for(int ans: output)
        {
            cout << i << " " << ans << "\n";
        }
    }
}