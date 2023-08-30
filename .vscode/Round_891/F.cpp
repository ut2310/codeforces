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
long long int t, n, q;
bool double_is_int(long trouble) {
    long long int temp = sqrt(trouble);
    return temp * temp == long(trouble);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        map<long long int, long long int> track;
        for(int i = 0; i < n; i++)
        {
            long long int temp; cin >> temp;
            if(track.count(temp) == 0)
            {
                track.insert(make_pair(temp, 1));
            }
            else
            {
                long long int x = track[temp];
                track[temp] = x + 1;
            }
        }
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            long long int x, y; cin >> x >> y;
            long long int disc = x * x - 4 * y;
            long long int res = 0;
            if(double_is_int(disc))
            {    
                if(disc > 0)
                {       
                    long long int a = sqrt(disc);
                    if((x + a) % 2 == 0)
                    {
                        long long int value1 = (x + a)/2;
                        long long int value2 = (x - a)/2;
                        res = track[value1] * track[value2];
                    }
                }
                else if(disc == 0)
                {
                    if(double_is_int(y))
                    {
                        long long int a = sqrt(y);
                        if(track.count(a) != 0)
                        {
                            long long int temp = track[a];
                            res = temp * (temp - 1)/2;
                        }
                    }
                }
            }
            cout << res << " ";
        }
        cout << "\n";

    }
}