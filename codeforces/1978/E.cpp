using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        string s, t; cin >> s >> t;
        vector<pair<ll, ll>> store(n);
        for(int i = 0; i < n; i++)
        {
            if(t[i] == '1') store[i] = make_pair(i, i);
            else
            {
                if(i == 0 || i == n - 1) store[i] = make_pair(-1, -1);
                else
                {
                    if(s[i - 1] == '0' || s[i + 1] == '0')
                    {
                        store[i] = make_pair(i - 1, i + 1);
                    }
                    else
                    {
                        store[i] = make_pair(-1, -1);
                    }
                }
            }
        }
        vector<pair<ll, ll>> storea(n);
        vector<ll> left;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') storea[i] = make_pair(i, i);
            else
            {
                if(i == 0 || i== n - 1) storea[i] = make_pair(-1, -1);
                else
                {
                    if(store[i + 1].first == -1 || store[i - 1].first == -1)
                    {
                        storea[i] = make_pair(-1, -1);
                    }
                    else
                    {
                        storea[i] = make_pair(store[i - 1].first, store[i + 1].second);
                    }
                }
            }
        }
    
        for(int i = 0; i < n; i++)
        {
            if(storea[i].first != -1) left.push_back(storea[i].first);
        }
        sort(left.begin(), left.end());
        // for(int i = 0; i < left.size(); i++)
        // {
        //     cout << left[i] << " ";
        // }
        ll q; cin >> q;
        for(int i = 0; i < q; i++)
        {
            ll l, r; cin >> l >> r;
            l--;
            r--;
            ll cnt = 0;
            //cout << l << " " << r << "\n";
            if(r - 4 >= l)
            {
                auto itr2 = lower_bound(left.begin(), left.end(), l);
                ll resl = -1;
                if(itr2 != left.end())
                {
                    resl = *itr2;
                }
                ll resr = -1;
                auto itr = upper_bound(left.begin(), left.end(), r - 4);
                if(itr == left.end())
                {
                    resr = left.size() - 1;
                }
                else
                {
                    resr = (*itr) - 1;
                }
                //cout << resl << " " << resr << "\n";
                if(resl >= 0 && resl < left.size() && resr >= 0 && resr < left.size()) cnt += (resr - resl + 1);
            }
            ll start = max(r - 3, l);
            //cout << start << "\n";
            for(int j = start; j <= r; j++)
            {
                if(storea[j].first >= start && storea[j].second <= r)
                {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
}