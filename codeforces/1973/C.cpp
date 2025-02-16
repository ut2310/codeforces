#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<ll, ll>> first;
        vector<pair<ll, ll>> first2;
        bool flag = false;
        for(int i = 1; i < n - 1; i+=2)
        {
            if(a[i] == 1)
            {
                flag = true;
            }
            first.push_back(make_pair(a[i], i));
        }
        for(int i = 0; i < n; i+=2)
        {
            first2.push_back(make_pair(a[i], i));
        }
        sort(first.begin(), first.end());
        sort(first2.begin(), first2.end());
        ll curr = n;
        vector<ll> output1(n);
        for(int i = 0; i < first.size(); i++)
        {
            output1[first[i].second] = curr;
            curr--; 
        }
        curr = 1;
        for(int i = first2.size() - 1; i >= 0; i--)
        {
            output1[first2[i].second] = curr;
            curr++;
        }
        output1[n - 1] = curr;




        vector<pair<ll, ll>> second;
        vector<pair<ll, ll>> second2;
        for(int i = 2; i < n; i+=2)
        {
            second.push_back(make_pair(a[i], i));
        }
        for(int i = 1; i < n; i+=2)
        {
            second2.push_back(make_pair(a[i], i));
        }
        sort(second.begin(), second.end());
        sort(second2.begin(), second2.end());
        ll curr2 = n;
        vector<ll> output2(n);
        for(int i = 0; i < second.size(); i++)
        {
            output2[second[i].second] = curr2;
            curr2--; 
        }
        curr2 = 1;
        for(int i = second2.size() - 1; i >= 0; i--)
        {
            output2[second2[i].second] = curr2;
            curr2++;
        }
        output2[0] = curr2;

        if(!flag)
        {
            for(int i = 0; i < n; i++)
            {
                cout << output1[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                cout << output2[i] << " ";
            }
            cout << "\n";
        }
        

    }
}