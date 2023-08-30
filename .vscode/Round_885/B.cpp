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
    int t, n, k, color[100005];
    bool check(int step, vector<int> &plank)
    {
        int counter = 0;
        int prev = 1;
        bool flag = false;
        set<int> store;
        int i = step + 1;
        for(i = step + 1; i <= n; i+= step + 1)
        {
            for(int j = prev; j <= i; j++)
            {
                if(store.count(plank[j]) == 0)
                {
                    color[plank[j]]+= 1;
                    store.insert(plank[j]);
                }
            }
            store.clear();
            counter++;
            prev = i + 1;
        }
        if(i < n)
        {
            int temp = min(i, n);
            for(int j = prev; j <= temp; j++)
            {
                if(store.count(plank[j]) == 0)
                {
                    color[plank[j]]+= 1;
                    store.insert(plank[j]);
                }
            }
            store.clear();
            counter++;
            prev = i + 1;
        }
        for(int i = 1; i <= k; i++)
        {
            if(color[i] >= counter - 1)
            {
                flag = true;
            }
        }
        fill(color, color + 100003, 0);
        return flag;
    }
    int main()
    {  
        cin >> t;
        while(t-->0)
        {
            cin >> n >> k;
            vector<int> input;
            input.push_back(-1);
            for(int i = 0; i < n; i++)
            {
                int temp; cin >> temp;
                input.push_back(temp);
            }
            int low = 0;  int high = n;
            while(low < high)
            {
                int mid = (low + high)/2;
                if(check(mid, input))
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
                //cout << low << " " << high << "\n";
            }
            cout << low << "\n";
        }
    }