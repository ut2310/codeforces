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
#define MAXN 22
int arr[MAXN][MAXN];
int main()
{
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int R, C;
        cin >> R >> C;
        arr[R - 1][C - 1] = 1;
        arr[R - 1][0] = 1;
        arr[0][0] = 1;
        arr[0][C - 1] = 1;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(arr[i][j] != 1 && (i == 0 || j == 0 || i == R - 1 || j == C - 1))
                {
                    if(i == 0 || i == R - 1)
                    {
                        if(arr[i][j - 1] == 0 && arr[i][j + 1] == 0)
                        {
                            arr[i][j] = 1;
                        }
                    }
                    if(j == 0 || j == C - 1)
                    {
                        if(arr[i - 1][j] == 0 && arr[i + 1][j] == 0)
                        {
                            arr[i][j] = 1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < R; i++)
        {
            cout << "\n";
            for(int j = 0; j < C; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}