using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>

int main()
{
    int low = 1;
    int high = 1e6;
    while(low < high)
    {
        int mid = (low + high + 1)/2;
        cout << mid << endl << flush;
        string temp; cin >> temp;
        if(temp == ">=")
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "! " << low << endl << flush;
    
}