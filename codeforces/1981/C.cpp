using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
ll arr[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        bool flag = true;
        ll n; cin >> n;
        vector<ll> a(n);
        ll cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] != -1) cnt++;
        }
        //cerr << cnt << "\n";
        if(cnt >= 1)
        {
            ll p0 = -1;
            for(int i = 0; i < n; i++)
            {
                if(a[i] != -1)
                {
                    arr[i] = a[i];
                    p0 = i;
                    break;
                }
            }
            bool flag5 = true;
            for(int i = p0 - 1; i >= 0; i--)
            {
                if(flag5)
                {
                    arr[i] = arr[i + 1] * 2;
                    flag5 = false;
                } 
                else
                {
                    arr[i] = arr[i + 1]/2;
                    flag5 = true;
                } 
            }
            set<ll> powers;
            ll curr = 1;
            map<ll, ll> store;
            for(int i = 0; i <= 30; i++)
            {
                powers.insert(curr);
                store[curr] = i;
                curr *= 2;
            }
            //cerr << p0 << "\n";
            for(int i = p0 + 1; i < n; i++)
            {
                //cerr << "HELLO\n";
                if(a[i] != -1)
                {
                    //get from a[i] to a[p0] in i - p0 operations
                    ll og1 = a[p0];
                    ll og2 = a[i];
                    ll operation1 = store[(*powers.upper_bound(og1))/2];
                    ll operation2 = store[(*powers.upper_bound(og2))/2];
                    //cerr << og1 << " " << og2 << " " << operation1 << " " << operation2 << "\n";
                    vector<ll> first;
                    first.push_back(og1);
                    vector<ll> second;
                    set<ll> storefirst;
                    storefirst.insert(og1);
                    while(og1 != 1)
                    {
                        og1/=2;
                        first.push_back(og1);
                        storefirst.insert(og1);
                    }
                    second.push_back(1);
                    ll last = 1;
                    ll start = 1;
                    ll sub = 0;
                    ll index = 0;
                    for(int i = operation2 - 1; i >= 0; i--)
                    {
                        if(og2 & (1 << i))
                        {
                            last *= 2;
                            last += 1;
                        }
                        else
                        {
                            last *= 2;
                        }
                        second.push_back(last);
                        if(storefirst.count(last) > 0)
                        {
                            start = last;
                            sub = operation2 - i;
                            index = operation2 - i;
                        }
                    }
                    // for(auto j: first)
                    // {
                    //     cout << j << " ";
                    // }
                    // cout << "\n";
                    // for(auto j: second)
                    // {
                    //     cout << j << " ";
                    // }
                    // cout << "\n";
                    // cerr << operation1 << " " << operation2 << " " << sub << "\n";
                    // cerr << i << " " << p0 << "\n";
                    if((operation1 + operation2 - (i - p0)) % 2 != 0) flag = false;
                    else
                    {
                        ll totaloperations = operation1 + operation2 - 2 * sub;
                        if(totaloperations > (i - p0)) flag = false;
                        else
                        {
                            ll pointer2 = 0;
                            bool flag3 = true;
                            for(int j = p0; j <= p0 + totaloperations; j++)
                            {
                                if(flag3)
                                {
                                    arr[j] = first[pointer2];
                                    if(first[pointer2] == start)
                                    {
                                        flag3 = false;
                                        pointer2 = index;
                                    }
                                    pointer2++;
                                }
                                else
                                {
                                    arr[j] = second[pointer2];
                                    pointer2++;
                                }
                            }
                            bool flag4 = true;
                            for(int j = p0 + totaloperations + 1; j <= i; j++)
                            {
                                if(flag4)
                                {
                                    arr[j] = arr[j - 1] * 2;
                                    flag4 = false;
                                } 
                                else
                                {
                                    arr[j] = arr[j - 1]/2;
                                    flag4 = true;
                                }
                            }
                        }
                    }
                    if(!flag) break;
                    p0 = i;
                }
                else
                {
                    arr[i] = a[i];
                }
            }
            bool flag6 = true;
            for(int i = p0 + 1; i < n; i++)
            {
                if(flag6)
                {
                    arr[i] = arr[i - 1] * 2;
                    flag6 = false;
                }
                else
                {
                    flag6 = true;
                    arr[i] = arr[i - 1]/2;
                }
            }
        }
        if(flag)
        {
            if(cnt == 0)
            {
                for(int i = 0; i < n; i++)
                {
                    if(i % 2 == 0)
                    {
                        cout << 2 << " ";
                    }
                    else
                    {
                        cout << 1 << " ";
                    }
                }
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "-1\n";
        }
        for(int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }

    }
}