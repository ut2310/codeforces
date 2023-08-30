using namespace std;
#include <iostream>
#include <vector>
#include <numeric>
int main()
{
    long long int N;
    cin >> N;
    vector<long long int> output;
    long long int res = 1;
    for(int i = 1; i < N; i++)
    {
        if(gcd(i, N) == 1)
        {
            res = (res * i) % N;
            output.push_back(i);
        }
    }
    if(res != 1)
    {
        output.pop_back();
    }
    cout << output.size() << "\n";
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}