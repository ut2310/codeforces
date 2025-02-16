using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> temp;
    bool flag2 = true;
    for(int j =0; j < n; j++)
    {
        if(a[j] != 0)
        {
            temp.push_back(a[j]);
            flag2 = false;
        }
        else
        {
            temp.push_back(0);
        }
        
    }
    ll low = 1;
    ll high = n;
    if(!flag2)
    {
        while(low < high)
        {
            ll mid = (low + high)/2;
            ll range = (high - low + 1)/2;
            bool flag = true;
            vector<ll> b(n);
            for(int j = 0; j < n; j++)
            {
                ll next = (j + range) % n;
                b[j] = temp[j] ^ temp[next];
                if(b[j] != 0) flag = false;
            }
            if(flag)
            {
                high = mid;
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    temp[j] = b[j];
                }
                low = mid + 1;
            }
            //if(i == 2) cout << low << " " << high << "\n";
            //cout << low << " " << high << "\n";
        }
    }
    else
    {
        low = 0;
    }

    cout << low << "\n";
}