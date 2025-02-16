using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll arr[MAXN], N; //keeps track of changes
void process1(vector<ll> &a)
{
    //cerr << "hi\n";
    ll og = a.size();
    ll p1 = 0;
    vector<ll> get_next(N + 1);
    for(int i = 1; i <= N; i++){
        if(i <= a[p1]){
            get_next[i] = a[p1];
        }
        else{
            p1++;
            if(p1 == a.size()){
                break;
            }
            get_next[i] = a[p1];
        }
    }
    // for(int i = 1; i <= N; i++){
    //     cerr << get_next[i] << " ";
    // }
    cerr << "\n";
    for(int i = 1; i <= N; i++){
        ll groups = 1;
        ll curr = a[0];
        while(curr != 0 && curr + i + 1 <= a[a.size() - 1]){
            curr = get_next[curr + i + 1];
            groups++;
        }
        if(groups < og){
            arr[i] += og - groups;
        }
        og = groups;
    }
}
void process2(vector<ll> &a)
{
    //cerr << "hi2\n";
    for(int i = 1; i < a.size(); i++){
        ll low = 1; ll high = N;
        while(low < high){
            ll mid = (low + high)/2;
            //need to check if mid is good enough to get at least 
            ll groups = 1;
            ll prev = a[0];
            for(int i = 1; i < a.size(); i++){
                if(a[i] - prev > mid){
                    groups++;
                    prev = a[i];
                }
            }
            if(groups <= i){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        arr[low]++;
    }
}
int main()
{
    cin >> N;
    vector<vector<ll>> track(N + 1);
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        track[a[i]].push_back(i + 1);
    }
    for(int i = 1; i <= N; i++){
        if(track[i].size() > 0){
            if(track[i].size() * track[i].size() <= N){
                process2(track[i]);
            }
            else{
                process1(track[i]);
            }
        }
        // for(int j = 1; j <= N; j++){
        //     cout << arr[j] << " ";
        // }
        // cout << "\n";
    }
    vector<ll> res(N + 1);
    res[0] = N;
    for(int i = 1; i <= N; i++){
        res[i] = res[i - 1] - arr[i];
        cout << res[i] << "\n";
    }
}