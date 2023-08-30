using namespace std;
#include <iostream>
#include <vector>
int main()
{
    int n, q, left, right;
    string s;
    cin >> n >> q >> s;
    vector<long long int> ps;
    ps.push_back(0);
    for(int i = 0; i < s.size(); i++)
    {
        int temp = (int) s.at(i);
        long long int temp2 = ps[ps.size() - 1] + temp - 96;
        ps.push_back(temp2);
    }
    for(int i = 0; i < q; i++)
    {
        cin >> left >> right;
        long long int ans = ps[right] - ps[left - 1];
        cout << ans << "\n";
    }

}