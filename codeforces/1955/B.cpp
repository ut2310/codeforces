#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, c, d; cin >> n >> c >> d;
        vector<ll> a(n * n);
        map<ll, ll> elements;
        for(int i = 0; i < n * n; i++)
        {
            cin >>a[i];
            elements[a[i]]++;
        }
        sort(a.begin(), a.end());
        ll s1 = a[0];
        ll s = s1;
        bool flag = true;
        map<ll, ll> freq;
        freq[s1]++;
        for(int i = 1; i < n; i++)
        {   
            s += c;
            freq[s]++;
        }   
        if(flag)
        {
            for(int i = 1; i < n; i++)
            {
                s1 += d;
                ll curr = s1;
                for(int j = 0; j < n; j++)
                {
                    freq[curr]++;
                    curr += c;
                }
            }
        }
        for(auto j: freq)
        {
            //cout << j.first << " " << j.second << "\n";
            if(elements[j.first] != j.second) flag = false;
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }
}