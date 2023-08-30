using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
int t, n, q;
struct portal
{
    int l, r, a, b;
    portal(int l, int r, int a, int b)
    {
        this->l = l;
        this->r = r;
        this->a = a;
        this->b = b;
    }

};
bool compareTo(portal x, portal y)
{
    return y.r - x.r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        vector<portal> events;
        for(int i = 0; i < n; i++)
        {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            events.push_back(portal(l, r, a, b));
        }
        sort(events.begin(), events.end(), compareTo);
        for(int i = 0; i < events.size(); i++)
        {
            cout << i << " " << events[i].r << " ";
        }
        // cin >> q;
        // for(int i = 0; i < q; i++)
        // {
        //     int start; cin >> start;
        // }   
    }
}