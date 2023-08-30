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
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int size; cin >> size;
        vector<int> l;
        for(int i = 0; i < size; i++)
        {
            int temp; cin >> temp;
            l.push_back(temp);
        }
        vector<int> vect2;
        for(int i = 0; i < size; i++)
        {
            vect2.push_back(l[i]);
        }
        sort(vect2.begin(), vect2.end());
        int target = vect2[vect2.size() - 1];
        int ans = -1;
        for(int i = 0; i < size; i++)
        {
            if(l[i] == target)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
