using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 2005
#define ALPHABETSIZE 26

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<pair<ll, ll>> intervals(n + 1);
        for(int i = 0; i < n; i++){
            ll size; cin >> size;
            vector<ll> a(size);
            set<ll> track;
            for(int j =0; j < size; j++){
                cin >> a[j];
                track.insert(a[j]);
            }
            ll cnt, res1, res2;
            cnt = 0;
            res1 = 0;
            res2 = 0;
            for(int j = 0; j <= size + 4; j++){
                if(cnt == 2){
                    break;
                }
                if(track.count(j) == 0){
                    if(cnt == 0){
                        res1 = j;
                        cnt++;
                    }
                    else if(cnt == 1){
                        res2 = j;
                        cnt++;
                    }
                }
            }
            intervals[i + 1] = {res1, res2};
        }
        intervals[0]  = {-1, -1};
        sort(intervals.begin(), intervals.end());
        vector<ll> dp(n + 1);
        dp[1] = intervals[1].first;
        set<ll> track; track.insert(dp[1]);
        for(int i = 2; i <= n; i++){
            if(track.count(intervals[i].first) > 0){
                track.insert(intervals[i].second);
                dp[i] = max(dp[i - 1], intervals[i].second);
            }
            else{
                dp[i] = max(dp[i - 1], intervals[i].first);
                track.insert(intervals[i].first);
            }
        }
        ll X = dp[n];
        map<ll, ll> dp2;
        dp2[intervals[n].first] = max(X, intervals[n].second);
        for(int i = n - 1; i >= 1; i--){
            ll get = 0;
            if(dp2.count(intervals[i].first) > 0){
                get = dp2[intervals[i].first];
            }
            //cout << intervals[i].first << " " << intervals[i].second << " " << get << "c\n";
            if(dp2.count(intervals[i].second) > 0){
                dp2[intervals[i].first] = max(get, dp2[intervals[i].second]);
            }
            else{
                dp2[intervals[i].first] = max(get, intervals[i].second);
            }
            dp2[intervals[i].first] = max(X, dp2[intervals[i].first]);
        }
        // for(auto j: dp2){
        //     cout << j.first << " " << j.second << "hi\n";
        // }
        
        ll resX = 0;
        ll cntX = min(m + 1, X + 1);
        for(auto j: dp2){
            if(j.first <= m){
                if(j.first <= X){
                    cntX--;
                    resX += j.second;
                }
                else{
                    resX += j.second - j.first;
                }
            }
            
        }
        resX += cntX * X;
        //now just get sum from X + 1 - m
        if(m > X){
            resX += (m - X) * (m + X + 1)/2;
        }
        cout << resX << "\n";
    }
}