using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        string s; cin >> s;
        ll x = 0;
        ll y = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] =='N') y++;
            if(s[i] == 'S') y--;
            if(s[i] == 'W') x--;
            if(s[i] == 'E') x++;
        }
        if(x % 2 == 0 && y % 2 == 0)
        {
            x/=2;
            y/=2;
            ll cx = 0;
            ll cy = 0;
            set<ll> store;
            for(int i = 0; i < n; i++)
            {
                if(cx < x)
                {
                    if(s[i] == 'E')
                    {
                        store.insert(i);
                        cx++;
                    }
                }
                if(cx > x)
                {
                    if(s[i] == 'W')
                    {
                        store.insert(i);
                        cx--;
                    }
                }
                if(cy > y)
                {
                    if(s[i] == 'S')
                    {
                        store.insert(i);
                        cy--;
                    }
                }
                if(cy < y)
                {
                    if(s[i] == 'N')
                    {
                        store.insert(i);
                        cy++;
                    }
                }
            }
            if(store.size() == 0 && n == 2)
            {
                cout << "NO\n";
            }
            else if(store.size() == 0)
            {
                string res = "";
                res.push_back('R');
                bool flag = false;
                for(int i = 1; i < n; i++)
                {
                    if(!flag)
                    {
                        if(s[i] == 'S' && s[0]=='N')
                        {
                            res.push_back('R');
                            flag = true;
                        }
                        else if(s[i] == 'N' && s[0]=='S')
                        {
                            res.push_back('R');
                            flag = true;
                        }
                        else if(s[i] == 'E' && s[0]=='W')
                        {
                            res.push_back('R');
                            flag = true;
                        }
                        else if(s[i] == 'W' && s[0]=='E')
                        {
                            res.push_back('R');
                            flag = true;
                        }
                        else res.push_back('H');
                    }
                    else
                    {
                        res.push_back('H');
                    }
                    
                }
                cout << res << "\n";
            }
            else
            {
                string res = "";
                for(int i = 0; i < n; i++)
                {
                    if(store.count(i) > 0)
                    {
                        res.push_back('R');
                    }
                    else
                    {
                        res.push_back('H');
                    }
                }
                cout << res << "\n";
            }
            
        }
        else
        {
            cout << "NO\n";
        }

    }
}