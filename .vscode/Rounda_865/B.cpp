using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
using namespace std;
int t, a;
int main()
{
    cin >> t; 
    while(t-->0)
    {
        cin >> a;
        int track = 2 * a;
        int track2 = 2;
        for(int i = 0; i < a; i++)
        {
            if(i % 2 == 0)
            {
                cout << track << " ";
                track -= 2;
            }
            else
            {
                cout << track2 << " ";
                track2 += 2;
            }
        }
        cout << "\n";
        track = 1;
        track2 = a + 1;
        for(int i = 0; i < a; i++)
        {
            if(i % 2 == 0)
            {
                cout << track << " ";
                track += 2;
            }
            else
            {
                cout << track2 << " ";
                track2 += 2;
            }
        }
        cout << "\n";
    }

}