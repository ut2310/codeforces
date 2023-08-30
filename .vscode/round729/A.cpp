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
int main()
{
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        int countE;
        int countO;
        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            if(temp % 2 == 0)
            {
                countE++;
            }
            else
            {
                countO++;
            }
        }
        if(countE == countO)
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }
}