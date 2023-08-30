using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

int main()
{
    long long int size, k, diff;
    cin >> size >> k >> diff;
    vector<long long int> input;
    for(int i = 0; i < size; i++)
    {
        long long int temp;
        cin >> temp;
        input.push_back(temp);
    }
    sort (input.begin(), input.end());
    vector<long long int> np;
    for(int i = 1; i < size; i++)
    {
        if(input[i] - input[i - 1] > diff)
        {
            long long int temp = input[i] - input[i - 1];
            if(temp % diff == 0)
            {
                np.push_back(temp/diff - 1);
            }
            else
            {
                np.push_back(temp/diff);
            }
        }
    }
    sort (np.begin(), np.end());
    int counter = 0;
    while(k > 0 && counter < np.size())
    {
        k -= np[counter];
        if(k < 0)
        {
            break;
        }
        counter += 1;
    }
    long long int res = np.size() - counter + 1;
    cout << res;
    return 0;
}