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
long long int find_length(long long int x)
{
    if(x == 0)
    {
        return 3;
    }
    else
    {
        return 2 * find_length(x - 1) + x + 3;
    }
}
char find_position(long long int current_length, int K)
{
    long long int prevlength = (current_length - K - 3)/2;
    if(N <= prevlength)
    {
        return find_position(prevlength, K - 1);
    }
    else if(N > prevlength && N <= prevlength + K + 3)
    {
        if(prevlength + 1 == N)
        {
            return 'm';
        }
        else
        {
            return 'o';
        }
    }
    else
    {
        N = N - (prevlength + K + 3);
        return find_position(prevlength, K - 1);
    }
}
int main()
{
    cin >> N;
    long long int big_length = find_length(29);
    char res = find_position(big_length, 29);
    cout << res;
}