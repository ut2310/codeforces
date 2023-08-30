using namespace std;
#include <iostream>
#include <vector>
#include <map>
int main()
{
    int t, size;
    cin >> t;
    while(t-->0)
    {
        cin >> size;
        vector<long long int> input;
        map<long long int, vector<int>> mp;
        for(int i = 0; i < size; i++)
        {
            int temp;
            cin >> temp;
            input.push_back(temp);
        }
        for(int i = 0; i < size; i++)
        {
            mp[input[i]].push_back(i + 1);
        }
        long long int res = 0;
        for(auto x: mp)
        {
            vector<int> current = x.second;
            vector<long long int> ps;
            long long int counter = 0;
            if(current.size() >= 2)
            {
                for(int i = 0; i < current.size(); i++)
                {
                    counter += size - current[i] + 1;
                    ps.push_back(counter);
                }
                for(int i = 0; i < current.size() - 1; i++)
                {
                    res += current[i] * (ps[ps.size() - 1] - ps[i]);
                }
            }

        }
        cout << res << "\n";
    }
}