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
    int Q;
    cin >> Q;
    for(int j = 0; j < Q; j++)
    {
        int N;
        cin >> N;
        long long int sum = 0;
        for(int i = 0; i < N; i++)
        {
            long long int temp;
            cin >> temp;
            sum += temp;
        }
        long long int a = sum % N;
        long long int b = N - (sum % N);
        cout << a * b << "\n";
    }
}