using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
bool check(map<ll, ll> &freq, ll number, ll times)
{
    //cerr << number << " " << times << " " << freq[number]  << "\n";
    if(number == 1 && freq[number] < times){
        return false;
    }
    if(freq.count(number) > 0){
        if(freq[number] >= times){
            freq[number] -= times;
            times = 0;
            return true;
        }
        times-=freq[number];
        freq[number] = 0;
    }
    if(number % 2 == 1){
        bool flag1 = check(freq, number/2, times);
        bool flag2 = check(freq, number/2 + 1, times);
        if(!flag1 || !flag2){
            return false;
        }
        return true;
    }
    return check(freq, number/2, 2 * times);
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<ll> a(n); vector<ll> b(m);
        map<ll, ll> freq;
        ll get1 = 0; ll get2 = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;
            get1 += a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
            get2 += b[i];
        }
        //cerr << get1 << " " << get2 << "\n";
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(get1 != get2){
            cout << "NO\n";
            continue;
        }
        bool flag = true;
        for(int i = m - 1; i >= 0; i--){
            ll curr = b[i]; ll times1 = 1; ll curr2 = b[i] + 1; ll times2 = 0;
            while(curr > 0 && (curr * times1 + curr2 * times2) > 0){
                //cout << curr << " " << times1 << " " << curr2 << " " << times2 << "\n";
                if(times1 > 0){
                    if(freq[curr] >= times1){
                        freq[curr] -= times1;
                        times1 = 0;
                    }
                    else{
                        times1 -= freq[curr];
                        freq[curr] = 0;
                    }
                }
                if(times2 > 0){
                    if(freq[curr2] >= times2){
                        freq[curr2] -= times2;
                        times2 = 0;
                    }
                    else{
                        times2 -= freq[curr2];
                        freq[curr2] = 0;
                    }
                }
                ll temp1 = times1; ll temp2 = times2;
                if(curr % 2 == 1) times2 += temp1;
                else times1 += temp1;
                if(curr2 % 2 == 0) times2 += temp2;
                else times1 += temp2;
                curr /= 2;
                curr2 = curr + 1;
            }
            //cout << "\n\n";
            if(curr2 == 1 && times2 > 0){
                if(freq[curr2] >= times2){
                    freq[curr2] -= times2;
                    times2 = 0;
                }
                else{
                    times2 -= freq[curr2];
                    freq[curr2] = 0;
                }
            }
            if(curr * times1 + curr2 * times2 > 0) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}