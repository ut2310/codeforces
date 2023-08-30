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
#define MAXN 10005
int N, L;
int knots[MAXN];
int main()
{
    cin >> N >> L;
    vector<int> count;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        knots[temp] = 1;
        count.push_back(temp);
    }
    sort(count.begin(), count.end());
    for(int i = 1; i < L; i++)
    {
        bool flag = true;
        if(i <= L - i + 1)
        {
            for(int j = 0; j < count.size(); j++)
            {
                //cout << count[j] << " " << knots[count[j]] << " " << knots[i - count[j] + i] << "\n";
                if(count[j] >= i)
                {
                    break;
                }
                if(knots[i - count[j] + i] != 1)
                {
                    flag = false;
                }    
            }
        }
        else
        {
            for(int j = count.size() - 1; j >= 0; j--)
            {
                if(count[j] <= i)
                {
                    break;
                }
                if(knots[i - (count[j] - i)] != 1)
                {
                    flag = false;
                }    
            }
        }
        if(flag)
        {
            cout << i << "\n";
        }
    }
}