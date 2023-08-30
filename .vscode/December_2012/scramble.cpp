/*
USER: ut23101
LANG: C++17
TASK: scramble
*/
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
int N;
#define MAXN 50005
int arr[MAXN];
void print(vector<pair<string, int>> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second;
        cout << "\n";
    }
    cout << "\n";
}
vector<int> binarysearch(vector<pair<string, int>> a, vector<pair<string, int>> b)
{
    vector<int> output(a.size());
    for(int i = 0; i < a.size(); i++)
    {
        int low = 0;
        int high = b.size();
        while(low < high)
        {
            int mid = (low + high)/2;
            if(a[i].first.compare(b[mid].first) <= 0)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        output[a[i].second] = low;
    }
    return output;
}
int main()           
{   
    freopen("scramble.in", "r", stdin);
	freopen("scramble.out", "w", stdout);
    vector<string> input;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        input.push_back(temp);
    }   
    vector<pair<string, int>> best;
    vector<pair<string, int>> worst;
    for(int i = 0; i < N; i++)
    {
        string sorted_string = input[i];
        sort(sorted_string.begin(), sorted_string.end());
        string reverse = "";
        for(int j = sorted_string.size() - 1; j >= 0; j--)
        {
            reverse = reverse + sorted_string[j];
        }
        best.push_back(make_pair(sorted_string, i));
        worst.push_back(make_pair(reverse, i));
        if(sorted_string == reverse)
        {
            arr[i] = 1;
        }
    }
    sort(best.begin(), best.end());
    sort(worst.begin(), worst.end());
    vector<int> a1 = binarysearch(best, worst);
    vector<int> a2 = binarysearch(worst, best);
    for(int i = 0; i < N; i++)
    {
        cout << (a1[i] + 1) << " " << (a2[i] + arr[i]) ;
        cout << "\n";
    }
}   
//Start: 6:44