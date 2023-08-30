using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
int t, a;
vector<int> input;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> a;
        for(int i = 0; i < a; i++)
        {
            int temp; cin >> temp;
            input.push_back(temp);
        }
    }

}