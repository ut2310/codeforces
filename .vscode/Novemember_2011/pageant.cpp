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


int R, C;
char** input;
int** ff;
int main()
{
    freopen("pageant.in", "r", stdin);
	freopen("pageant.out", "w", stdout);
    cin >> R >> C;
    input = new char*[R];
    for(int i = 0; i < R; ++i)
    {
        input[i] = new char[C];
    }
    ff = new int*[R]; //floodfill array
    for(int i = 0; i < R; ++i)
    {
        ff[i] = new int[C];
    }
    for(int i = 0; i < R; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0; j < C; j++)
        {
            input[i][j] = temp.at(j);
        }
    }
    int count = 1;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(input[i][j] == 'X' && ff[i][j] == 0)
            {
                floodfill(count, i, j);
                count++;
            }
        }
    }
    
}
bool check_bounds(int row, int col)
{
    if(row >= 0 && row < R && col >= 0 && col < C)
    {
        return true;
    }
    return false;
}
void floodfill(int count, int row, int col)
{
    ff[row][col] = count;
    for(int i = -1; i <= 1; i+= 2)
    {
        for(int j = -1; j <= 1; j+= 2)
        {
            if(check_bounds(row + i, col + j))
            {
                if(input[row + i][col + j] == 'X' && ff[row + i][col + j] == 0)
                {
                    floodfill(count, row + i, col + j);
                }
            }
        }
    }   

}