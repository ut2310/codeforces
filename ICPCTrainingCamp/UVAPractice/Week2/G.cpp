using namespace std;
#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define MAXN 100005   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
pair<ld, ld> dp[MAXN];
ll n, p, c; 
ld calc_time(ld s1, ld s2)
{
    return (ld)c/(ld)(s1 - s2);
}
int main()
{
    cout << fixed << setprecision(8);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> p >> c;
    vector<pair<ll, ld>> a;
    a.push_back({0, 1});
    ld prev = 1;
    for(int i = 0; i < p; i++){
        ll t; cin >> t;
        ll temp1, temp2; cin >> temp1 >> temp2;
        ld get = (double) temp2/ (double) temp1;
        if(get <= prev){
            prev = get;
            a.push_back({t, get});
        }
    }
    if(a.size() == 1){
        cout << n << "\n";
        return 0;
    }
    else if(a[1].ff >= n){
        cout << n << "\n";
        return 0;
    }
    deque<pair<ld, ld>> track;
    ll age = a[1].ff; track.push_back({a[1].ff, a[0].ss});
    ll index = 1;
    while(index < a.size()){
        ld time_passed = (ld) c/ (ld) (track[track.size() - 1].ss - a[index].ss);
        ld speed = track[track.size() - 1].ss; ld curr_speed = a[index].ss;
        ld time = track[track.size() - 1].ff;
        if(a[index].ff < time){
            //ok we can for sure just use a[index].ff first
            ld worse_speed = track[0].ss;
            ld prev_time = track[0].ff;
            track.pop_front();
            track.push_front({a[index].ff, worse_speed});
            age += (a[index].ff - prev_time) * worse_speed
            ld time_pass = calc_time(worse_speed, curr_speed);
            track.pop_back();
            track.push_back({a[index].ff + time_pass, curr_speed});
        }
        if(age + speed * time_passed > n){
            //keep the current speed
        }   
        else if(a[index].ff < time){

        }
        index++;
        //this is how much time needs to pass for me to use it

    }
    dp[1] = {a[1].ff, 1};
    ld age = a[1].ff;
    for(int i = 2; i <= p + 1; i++){
        ld traveld = 0; 
        if(i == p + 1) traveld = n - age;
        else traveld = a[i].ff - a[i - 1].ff;
        if(i <= p){
            ld c1 = (1/dp[i - 1].ss) * traveld; ld c2 = c + (1/a[i - 1].ss) * (traveld);
            if(c1 <= c2){
                dp[i].ff += traveld * dp[i - 1].ss + dp[i - 1].ff;
                dp[i].ss = dp[i - 1].ss;
                age += c1;
            }
            else{
                dp[i].ff += (traveld - c) * (a[i - 1].ss) + dp[i - 1].ff;
                dp[i].ss = a[i - 1].ss;
                age += c2;
            }+6
        }
        else{
            if(traveld * dp[i - 1].ss >= (traveld - c) * a[i - 1].ss){
                age = a[p].ff + traveld * dp[i - 1].ss;
            }
            else{
                age = a[p].ff + (traveld - c) * a[i - 1].ss;
            }
        }
        
        //cout << age << " " << traveld << " " << i << " " << dp[i].ff << " " << dp[i].ss << "\n";
    }
    cout << age << "\n";
}