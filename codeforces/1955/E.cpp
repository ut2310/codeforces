#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {   
        ll n; cin >> n;
        string s; cin >> s;
        ll res = -1;
        for(int i = s.size(); i >= 1; i--)
        {
            bool flag = true;
            ll curr1 = 0;
            vector<ll> track;
            for(int j = 0; j <= s.size() - i; j++)
            {
                ll comp = 1 - (s[j] - '0');
                if(j - i >= 0) curr1 -= track[j - i];
                if(curr1 % 2 == comp % 2)
                {
                    track.push_back(0);
                } 
                else
                {
                    track.push_back(1);
                    curr1++;
                }
                // if(s[j] == prev) track.push_back(0);
                // else track.push_back(1);
                // prev = s[j];
            }
            // for(int j = 0; j < track.size(); j++)
            // {
            //     cout << track[j] << " ";
            // }
            // cout << "\n";
            ll p1 = track.size() - 1;
            ll curr = 0;
            for(int j = s.size() - 1; j > s.size() - i; j--)
            {
                if(p1 >= 0) curr += track[p1];
                if(s[j] == '1' && curr % 2 != 0) flag = false;
                if(s[j] == '0' && curr % 2 == 0) flag = false;
                p1--;
            }
            if(flag)
            {
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
}