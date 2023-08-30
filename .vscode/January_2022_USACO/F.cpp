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
int Q;
vector<int> decToBinary(int n)
{
    // array to store binary number
    vector<int> output;

    // counter for binary array
    int i = 0;
    while (n > 0) 
    {
        if(n % 2 == 1)
        {
            output.push_back(i);
        }
        n = n / 2;
        i++;
    }
    return output;
}
int getResult(vector<int> t)
{
    long long int ans = 0;
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i] > 0)
        {
            ans += pow(2, i);
        }
    }
    return ans;
}
int main()
{
    vector<int> track;
    for(int i = 0; i < 30; i++)
    {
        track.push_back(0);
    }
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        string op;
        int numeral;
        cin >> op >> numeral;
        if(op.compare("+") == 0)
        {
            vector<int> temp = decToBinary(numeral);
            for(int j = 0; j < temp.size(); j++)
            {
                track[temp[j]]++;
            }
        }
        else
        {
            vector<int> temp = decToBinary(numeral);
            for(int j = 0; j < temp.size(); j++)
            {
                track[temp[j]]--;
            }
        }
        cout << getResult(track) << "\n";
    }
}