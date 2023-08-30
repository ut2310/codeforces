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
#define MAXN 100005
int n, arr[MAXN];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int avg = sum/n;
    int rem = sum%n;
    int counter = 0;
    int res = 0;
    for(int i = 0; i < n ; i++)
    {
        if(arr[i] < avg)
        {
            res += avg - arr[i];
        }
        else if(arr[i] > avg && counter < rem)
        {
            res += arr[i] - avg - 1;
            counter++;
        }
        else if(arr[i] > avg && counter >= rem)
        {
            res += arr[i] - avg;
        }
    }
    
    if(counter != rem)
    {
        res = res + rem - counter;
    }
    cout << res/2;

}