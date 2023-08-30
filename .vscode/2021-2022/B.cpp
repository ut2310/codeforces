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

int main()
{
    int Q;
    cin >> Q;
    for(int t = 0; t < Q; t++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        bool flag = false;
        vector<int> index;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s2.at(0) == s1.at(i))
            {
                index.push_back(i);
            }
        }
        for(int i = 0; i < index.size(); i++)
        {
            int temp = index[i];
            int counter = 0;
            while(s2.at(counter) == s1.at(temp))
            {
                if(counter == s2.length())
                {
                    flag = true;
                    break;
                }
                if(temp == s1.length())
                {
                    break;
                }
                int counter2 = counter;
                int temp2 = temp;
                while(s2.at(counter) == s1.at(temp))
                {
                    counter++;
                    temp--;
                    if(counter == s2.length() || temp == -1)
                    {
                        break;
                    }
                }
                if(counter == s2.length())
                {
                    flag = true;
                    break;
                }
                counter = counter2 + 1;
                temp = temp2 + 1;
                if(counter == s2.length())
                {
                    flag = true;
                    break;
                }
                if(temp == s1.length())
                {
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    /*
    1
    adbd
    adbda
    */
}