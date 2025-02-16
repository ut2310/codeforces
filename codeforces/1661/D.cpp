using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll res = 0;
    ll nextDiff = 0;
    queue<ll> track;
    ll track2 = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        //cout << a[i] << " " << nextDiff << "\n";
        a[i] -= nextDiff;
        if(a[i] > 0)
        {
            ll ops = 0;
            if(i >= k - 1)
            {
                ops = (a[i] + k - 1)/k;
                nextDiff += (k - 1) * ops;
            }
            else
            {
                ops = (a[i] + i)/(i + 1);
                nextDiff += i * ops;
            }
            track.push(ops);
            if(track.size() > k)
            {
                ll curr = track.front();
                track2 -= curr;
                track.pop();
            }
            nextDiff -= track2;
            track2 += ops;
            res += ops;
            //cout << a[i] << "hola " << ops << "\n";
        }
        else
        {
            track.push(0);
            if(track.size() > k)
            {
                ll curr = track.front();
                track2 -= curr;
                track.pop();
            }
            nextDiff -= track2;
            //cout << 0 << "\n";
        }
    }
    cout << res << "\n";
}