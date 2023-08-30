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
#define ll long long
ll t, n, m, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m >> d;
        vector<ll> input;
        input.push_back(1);
        for(int i = 0; i < m; i++)
        {
            ll temp; cin >> temp;
            input.push_back(temp);
        }
        input.push_back(n);
        sort(input.begin(), input.end());
        ll counter = 0;
        ll res = 0;        
        ll maxDiff = -1;
        for(int i = 1; i <= m; i++)
        {
            ll track = 0;
            track += (input[i] - input[i - 1]) / d;
            if((input[i] - input[i - 1]) % d == 0)
            {
                track+=1;
            }
            else
            {
                track +=2;
            }
            counter += track;
            track += (input[i + 1] - input[i])/d;
            if((input[i + 1] - input[i]) % d != 0)
            {
                track += 1;
                if(i == m)
                {
                    track--;
                }
            }
            
            ll compare = 0;
            compare += (input[i + 1] - input[i - 1])/d;
            if((input[i + 1] - input[i - 1]) % d == 0)
            {
                compare++;
            }
            else
            {
                compare += 2;
            }
            if(i == m)
            {
                if((input[i + 1] - input[i - 1]) % d != 0)
                {
                    compare--;
                }
            }
            //cout << input[i - 1] << " " << input[i] << "   "<< "Track: " << track << "     " << "Compare: " << compare << "\n";
            ll diff = track - compare;
            if(diff > maxDiff)
            {
                res = 1;
                maxDiff = diff;
            }
            else if(diff == maxDiff)
            {
                res++;
            }
        }
        counter -= m - 1;
        counter += (n - input[m])/d;
        ll res2 = counter - maxDiff;
        cout << res2 << " " << res << "\n";
    }
}