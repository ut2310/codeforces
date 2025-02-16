using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M;

int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> q(n + 1);
        vector<ll> k(n + 1);
        vector<ll> j(n + 1);
        vector<ll> vq(n + 1);
        vector<ll> vk(n + 1);
        vector<ll> vj(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> q[i];
            vq[q[i]] = i;
        }
        for(int i = 1; i <= n; i++){
            cin >> k[i];
            vk[k[i]] = i;
        }
        for(int i = 1; i <= n; i++){
            cin >> j[i];
            vj[j[i]] = i;
        }

        pair<pii, ll> track = {{1, 1}, 1};
        pair<pii, ll> index = {{vq[1], vk[1]}, vj[1]};
        pair<pii, ll> prev = {{1, 1}, 1};
        while(true){
            for(int i = prev.ff.ff; i <= index.ff.ff; i++){
                ll curr = q[i];
                if(vk[curr] > vk[track.ff.ss]){
                    track.ff.ss = curr;
                }
                if(vj[curr] > vj[track.ss]){
                    track.ss = curr;
                }
            }
            for(int i = prev.ff.ss; i <= index.ff.ss; i++){
                ll curr = k[i];
                if(vq[curr] > vq[track.ff.ff]){
                    track.ff.ff = curr;
                }
                if(vj[curr] > vj[track.ss]){
                    track.ss = curr;
                }
            }
            for(int i = prev.ss; i <= index.ss; i++){
                ll curr = j[i];
                if(vk[curr] > vk[track.ff.ss]){
                    track.ff.ss = curr;
                }
                if(vq[curr] > vq[track.ff.ff]){
                    track.ff.ff = curr;
                }
            }
            prev = index;
            index.ff.ff = vq[track.ff.ff];
            index.ff.ss = vk[track.ff.ss];
            index.ss = vj[track.ss];
            
        }
    }
}