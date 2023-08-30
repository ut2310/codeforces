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
int main()
{
    int Q;
    cin >> Q;
    for(int a = 0; a < Q; a++)
    {
        cin >> N;
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            v1.push_back(temp);
        }
        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            v2.push_back(temp);
        }
        long long int sum = 0;
        long long int psum = 0;
        for(int i = 0; i < N; i++)
        {
            if(v2[i] - v1[i] > 0)
            {
                psum += v2[i] - v1[i];
            }
            sum += v2[i] - v1[i];
        }
        if(sum!=0)
        {
            cout << "-1" << "\n";
        }
        else
        {
            cout << psum << "\n";
            for(int i = 0; i < N; i++)
            {
                while(v2[i] - v1[i] < 0)
                {
                    cout << i + 1 << " ";
                    for(int j = 0; j < N; j++)
                    {
                        if(v2[j] - v1[j] > 0)
                        {
                            v1[j]++;
                            cout << j + 1 << "\n";
                            break;
                        }
                    }
                    v1[i]--;
                }
            }
        }
    }
}