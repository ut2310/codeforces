using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 22
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll n;
void perform(vector<ll> &var, vector<vi> &arr)
{
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i][j] == arr[j][i]){
                continue;
            }
            if(var[j] == -1){
                var[j] = ((arr[i][j] < arr[j][i])? 0:1) - var[i];
                if(var[j] < 0) var[j] += 2;
            }
            else{
                ll flag = ((arr[i][j] < arr[j][i])? 0:1) - (var[i] + var[j]);
                if(flag % 2 != 0){
                    break;
                } 
                
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        cin >> n;
        vector<vi> arr(n, vi(n));
        vector<vi> arr2(n, vi(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
                arr2[i][j] = arr[i][j];
            }
        }
        vector<ll> var(n);
        for(int i = 1; i < n; i++){
            var[i] = -1;
        }
        perform(var, arr);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((var[i] + var[j]) % 2 != 0){
                    swap(arr[i][j], arr[j][i]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(i == 0) var[i] = 1;
            else var[i] = -1;
        }
        perform(var, arr2);
        // cout << stop.ff << " " << stop.ss << "\n";
        // for(int i = 0; i < n; i++){
        //     cout << var[i] << " ";
        // }
        // cout << "\n";
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((var[i] + var[j]) % 2 != 0){
                    swap(arr2[i][j], arr2[j][i]);
                }
            }
        }
        bool flag = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] < arr2[i][j]){
                    break;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(flag) cout << arr[i][j] << " ";
                else cout << arr2[i][j] << " ";
            }
            cout << "\n";
        }
    }
}