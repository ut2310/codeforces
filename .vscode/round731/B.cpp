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
int main()
{
	int t; cin >> t;
	while(t--)
    {
		string str;
		cin >> str;
		int l = 0; int r = str.length() - 1;
		vector<int> ans;
		while(l < r)
        {
			if(str[l] < str[r])
            {
				ans.push_back(str[r] - 'a');
				r--;
			}
			else if(str[l]>str[r])
            {
				ans.push_back(str[l] - 'a');
				l++;
			}
			else
            {
				break;
			}
		}
		if(l==r)
        {
			ans.push_back(str[l] - 'a');
		}
		else{
			cout << "NO" << endl;
			continue;
		}
		int len = ans.size();
		int i;
		for(i = 0; i < len; i++)
        {
			if((i+1)!=len-ans[i])
            {
                break;
            }
		}
		if(i==len)
        {
            cout << "YES" << endl;
        }
		else
        {
			cout <<"NO"<< endl;
		}
	}
}