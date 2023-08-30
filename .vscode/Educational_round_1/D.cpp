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
#define MAXN 1010
#define MAXM 1010
int R, C, Q;
char arr[MAXN][MAXM];
int ff[MAXN][MAXM];
int comp[MAXN * MAXM];
void floodfill(int r, int c, int count, int &sum)
{
    ff[r][c] = count;
    for(int i= -1; i <= 1; i+=2)
    {
        for(int j = -1; j <= 1; j+=2)
        {
            if(r + i >= 0 && r + i < R && c + j >= 0 && c + j < C)
            {
                if(arr[r + i][c + j] == '*')
                {
                    sum++;
                }
            }
        }
    }
    for(int i= -1; i <= 1; i+=2)
    {
        for(int j = -1; j <= 1; j+=2)
        {
            if(r + i >= 0 && r + i < R && c + j >= 0 && c + j < C)
            {
                if(ff[r + i][c + j] == 0 && arr[r + i][c + j] == '.')
                {
                    floodfill(r + i, c + j, count, sum);
                }
            }
        }
    }
}
int main()
{
    cin >> R >> C >> Q;
    for(int i = 0; i < R; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0; j < C; j++)
        {
            arr[i][j] = temp.at(j);
        }
    }
    int count = 1;
    int sum = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(ff[i][j] == 0 && arr[i][j] == '.')
            {
                sum = 0;
                floodfill(i, j, count, sum);
                comp[count] = sum;
                count++;
            }
        }
    }
    for(int i = 0; i < Q; i++)
    {
        int r, c;
        cin >> r >> c;
        cout << comp[ff[r][c]] << "\n";
    }
}