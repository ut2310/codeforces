using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
 
int t,n,m,k;
int a[305],b[305];
 
int main()
{
	cin >> t;
	while(t--)
    {
		cin >> k >> n >> m;
		for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
		for(int i = 1; i <= m; i++)
        {
            cin >> b[i];
        } 
		vector<int> res;
		int p1 = 1, p2 = 1;
		bool flag = true;
		while(p1 <= n || p2<=m)
        {
			if(p1<=n&&a[p1]==0)
            {
				res.push_back(a[p1]);
				k++;
				p1++;
			}
            else if(p2 <= m && b[p2] == 0)
            {
				res.push_back(b[p2]);
				k++;
				p2++;
			}
            else if(p1 <= n && a[p1] <= k)
            {
				res.push_back(a[p1]);
				p1++;
			}
            else if(p2 <= m && b[p2] <= k)
            {
				res.push_back(b[p2]);
				p2++;
			}
            else
            {
				flag=false;
				break;
			}
		}
 
		if(flag)
        {
			int len=res.size();
			for(int i = 0; i < len; i++)
            {
                cout << res[i] << " ";
            } 
            cout << "\n";
		}
        else
        {
            cout << "-1\n";
		}
	}
	return 0;
}
