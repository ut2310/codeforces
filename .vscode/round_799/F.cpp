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
#include <unordered_map>
int Q, N;
bool find3Numbers(vector<int> A, int arr_size)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Fix the second element as A[j]
        for (int j = i + 1; j < arr_size - 1; j++)
        {
 
            // Now look for the third number
            for (int k = j + 1; k < arr_size; k++)
            {
                if ((A[i] + A[j] + A[k]) % 10 == 3)
                {
                    return true;
                }
            }
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}
void print_map(std::unordered_map<int, int> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
int main()
{
    cin >> Q;
    while(Q-->0)
    {
        int N; cin >> N;
        unordered_map<int, int> cnt;
        for(int i = 0; i < N; i++)
        {
            int temp; cin >> temp;
            int num = temp % 10;
            if(cnt.find(num) == cnt.end())
            {
                cnt[num] = 1;
            }
            else
            {
                cnt[num]++;
            }
        }
        vector<int> elements;
        for(int i = 0; i < 10; i++)
        {
            if(cnt.find(i) != cnt.end())
            {
                if(cnt[i] > 3)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        elements.push_back(i);
                    }
                }
                else
                {
                    for(int j = 0; j < cnt[i]; j++)
                    {
                        elements.push_back(i);
                    }
                }
            }
        }
        bool res = find3Numbers(elements, elements.size());
        if(res)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}