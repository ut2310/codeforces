using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> a(n); vector<ll> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<pair<ll, ll>> track;
        for(int i = 0; i < n; i++)
        {
            track.push_back(make_pair(a[i], b[i]));
        }
        sort(track.begin(), track.end());
        ll m = (n - 1)/2;
        ll res = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(track[i].second == 1)
            {
                //cout << i << " " << track[i].first << " " << track[i].second << " " << m << "\n";
                if(i >= m && n % 2 == 1)
                {
                    res = max(res, k + track[i].first + track[m - 1].first);
                }
                else if(i < m && n % 2 == 1)
                {
                    res = max(res, k + track[i].first + track[m].first);
                }
                else if(i > m && n % 2 == 0)
                {
                    res = max(res, k + track[i].first + track[m].first);
                }
                else if(i <= m && n % 2 == 0)
                {
                    res = max(res, k + track[i].first + track[m + 1].first);
                }
            }
        }
        //cout << res << "\n";
        for(int i = n - 1; i >= 0; i--)
        {
            if(track[i].second == 0)
            {
                if(i >= m && n % 2 == 1)
                {
                    m--;
                }
                else if(i <= m && n % 2 == 0)
                {
                    m++;
                }
                if(res - track[i].first - track[m].first <= k)
                {   
                    ll initial = track[i].first;
                    //cout << initial << "\n";
                    ll low = track[m].first;
                    ll high = track[m].first + k;
                    while(low < high)
                    {
                        bool flag = true;
                        ll mid = (low + high + 1)/2;
                        //cout << mid <<"\n";
                        ll cnt = 0;
                        ll temp = k;
                        ll target = (n + 1)/2;
                        for(int j = n - 1; j >= 0; j--)
                        {
                            if(i != j && track[j].first >= mid)
                            {
                                cnt++;
                            }
                            else if(i != j && track[j].first < mid && track[j].second == 1 )
                            {
                                temp -= mid - track[j].first;
                                cnt++;
                            }
                            if(temp < 0)
                            {
                                flag = false;
                            } 
                            //cout << cnt << " " << target << " " << flag <<"\n";
                            if(cnt == target) break;
                            
                            
                        }
                        //cout << cnt << "\n";
                        if(cnt < target)
                        {
                            flag = false;
                        }
                        if(flag)
                        {
                            low = mid;
                        }
                        else{
                            high = mid - 1;
                        }
                    }
                    res = max(res, initial + low);
                }
                break;
            }
        }
        cout << res << "\n";

    }
}