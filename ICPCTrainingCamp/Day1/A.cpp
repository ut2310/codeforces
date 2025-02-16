using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        string s; cin >> s;
        if(s[0] > '1')
        {
            for(int i = 1; i <= 9; i++)
            {
                ll borrow = 0;
                ll digit = 0;
                bool flag = true;
                bool check0 = false;
                ll other_digit = ((s[s.size() - 1] - '0' - i) + 10) % 10;
                if(other_digit == 0) flag = false;
                ll stopping_point = -1;
                for(int j = s.size() - 1; j >= 0; j--)
                {
                    if(j == 0)
                    {
                        if(s[j] - '0' - i - borrow < 0)
                        {
                            flag = false;
                        }
                    }
                    if(s[j] - '0' - i - borrow < 0 ){
                        if((s[j] - '0' - i - borrow + 10) != other_digit) flag = false;
                        if(check0) flag = false;
                        borrow = 1;
                    }
                    else if(s[j] - '0' - i - borrow == 0){
                        borrow = 0;
                        if(!check0) stopping_point = j;
                        check0 = true;
                        
                    }
                    else{
                        borrow = 0;
                        if(check0) flag = false;
                        if((s[j] - '0' - i - borrow) != other_digit){
                            flag = false;
                        }
                    }
                }
                ll other_length = s.size() - 1 - stopping_point;
                if(flag)
                {
                    string s1 = "";
                    string s2 = "";
                    for(int j = 0; j < s.size(); j++)
                    {
                        s1.push_back('0' + i);
                    }
                    for(int j = 0; j < other_length; j++)
                    {
                        s2.push_back('0' + other_digit);
                    }
                    cout << s1 << " " << s2 << "\n";
                    break;
                }
            }
        }
        else
        {
            bool second_flag = false;
            for(int i = 1; i <= 1; i++)
            {
                ll borrow = 0;
                ll digit = 0;
                bool flag = true;
                bool check0 = false;
                ll other_digit = ((s[s.size() - 1] - '0' - i) + 10) % 10;
                if(other_digit == 0) flag = false;
                ll stopping_point = -1;
                for(int j = s.size() - 1; j >= 0; j--)
                {
                    if(j == 0)
                    {
                        if(s[j] - '0' - i - borrow < 0)
                        {
                            flag = false;
                        }
                    }
                    if(s[j] - '0' - i - borrow < 0 ){
                        if((s[j] - '0' - i - borrow + 10) != other_digit) flag = false;
                        if(check0) flag = false;
                        borrow = 1;
                    }
                    else if(s[j] - '0' - i - borrow == 0){
                        borrow = 0;
                        if(!check0) stopping_point = j;
                        check0 = true;
                        
                    }
                    else{
                        borrow = 0;
                        if(check0) flag = false;
                        if((s[j] - '0' - i - borrow) != other_digit){
                            flag = false;
                        }
                    }
                }
                ll other_length = s.size() - 1 - stopping_point;
                if(flag)
                {
                    string s1 = "";
                    string s2 = "";
                    for(int j = 0; j < s.size(); j++)
                    {
                        s1.push_back('0' + i);
                    }
                    for(int j = 0; j < other_length; j++)
                    {
                        s2.push_back('0' + other_digit);
                    }
                    cout << s1 << " " << s2 << "\n";
                    second_flag = true;
                    break;
                }
            }
            if(!second_flag){
                for(int i = 1; i <= 9; i++)
                {
                    ll borrow = 0;
                    ll digit = 0;
                    bool flag = true;
                    bool check0 = false;
                    ll other_digit = ((s[s.size() - 1] - '0' - i) + 10) % 10;
                    if(other_digit == 0) flag = false;
                    ll stopping_point = 0;
                    for(int j = s.size() - 1; j >= 1; j--)
                    {
                        if(s[j] - '0' - i - borrow < 0  && s[j] - '0' - i - borrow > -10){
                            if((s[j] - '0' - i - borrow + 10) != other_digit) flag = false;
                            if(check0) flag = false;
                            borrow = 1;
                        }
                        else if(s[j] - '0' - i - borrow == 0 || s[j] - '0' - i - borrow == -10){
                            if(s[j] - '0' - i - borrow == 0) borrow = 0;
                            else borrow = 1;
                            if(!check0) stopping_point = j;
                            check0 = true;
                        }
                        else{
                            borrow = 0;
                            if(check0) flag = false;
                            if((s[j] - '0' - i - borrow) != other_digit){
                                flag = false;
                            }
                        }
                    }
                    ll other_length = s.size() - 1 - stopping_point;
                    if(borrow != 1) flag = false;
                    if(flag)
                    {
                        string s1 = "";
                        string s2 = "";
                        for(int j = 0; j < s.size() - 1; j++)
                        {
                            s1.push_back('0' + i);
                        }
                        for(int j = 0; j < other_length; j++)
                        {
                            s2.push_back('0' + other_digit);
                        }
                        cout << s1 << " " << s2 << "\n";
                        break;
                    }
                }
            }
        }

    }

}