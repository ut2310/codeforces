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
    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
    int N;
    cin >> N;
    long long int res = 0;
    vector<int> input;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);
        res += temp;
    }
    res = res/N;
    long long int ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans += abs(input[i] - res);
    }
    ans/=2;
    cout << ans;

}
