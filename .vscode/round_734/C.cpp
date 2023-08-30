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
int arr[MAXN][5];
bool comp()
{

}
int main()
{
    int t, N;
    while(t-->0)
    {
        cin >> N;
        vector<string> input;
        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            input.push_back(s);
            for(int j = 0; j < s.size(); j++)
            {
                arr[i][(int)(s.at(j)) - 97]++;
            }
        }
        int res = 0;
        for(int i = 0; i < 5; i++)
        {
            int count = 0;
            vector<int> space;
            for(int j = 0; j < N; j++)
            {
                int sum = 0;
                for(int k = 0; k < 5; k++)
                {
                    sum += arr[j][k];
                }
                if(sum - arr[j][i] <= arr[j][i])
                space.push_back(arr[j][i] - (sum - arr[j][i]));
            }
            sort(space.begin(), space.end());
            int track = 0;
            for(int j = space.size() - 1; j >= 0; j--)
            {

                track += space[j];
                count++;
                if(track <= 0)
                {
                    track-= space[j];
                    count--;
                    break;
                }
            }
            if(count > res)
            {
                res = count;
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                arr[i][j] = 0;
            }
        }
        cout << res << "\n";
        
    }
}