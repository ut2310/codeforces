#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {   
        ll a, b, c;
        cin >> a >> b >> c;
        if((a + b + c) % 2 == 0)
        {
            if((a + b) <= c)
            {
                cout << (a + b) << "\n";
            }
            else
            {
                cout << (a + b + c)/2 << "\n";
            }
        }
        else
        {
            cout << "-1\n";
        }
        if((a + b) <= c)
        {

        }
    }
}