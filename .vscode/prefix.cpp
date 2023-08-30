/*
USER: ut23101
LANG: C++14
TASK: prefix
*/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;
struct dic
{
	char str[11];
	int len;
}
d[210];
char s[200100];
bool dp[200200]={0};
bool cmp(dic a,dic b)
{
	return a.len>b.len;
}
int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	char str[11], str2[80];
	int m = 0;
	while(scanf("%s", str) == 1)
	{
		if(strcmp(str,".") == 0)
        {
			break;
        }
		strcpy(d[m].str,str);
		d[m++].len = strlen(str);
	}
//	sort(d,d+m);
	s[0] = '\0';
	while(cin >> str2)
    {
		strcat(s ,str2);
    }
	int len1 = strlen(s);
	dp[0] = 1;
	int ans = 0;
	for(int i = 0;i < len1; i++)
	{
		if(!dp[i]) 
        {
            continue;
        }
		for(int j = 0; j < m; j++)
		{
			int flag = 0;
			for(int k = 0; k < d[j].len; k++)
			{
				if(d[j].str[k] != s[i+k])
				{
					flag=1;
                    break;
				}
			}
			if(!flag)
            {
				dp[i + d[j].len] = 1;
				if(i+d[j].len > ans)
                {
					ans = i+d[j].len;
                }
			}
		}
	}
	cout << ans << endl;
}