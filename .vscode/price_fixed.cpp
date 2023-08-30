using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
bool comp(pair<long long int, long long int> product1, pair<long long int, long long int> product2)
{
    return product1.second > product2.second;
}
int main()
{
    int N;
    vector<pair<long long int, long long int>> products;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        long long int temp1, temp2;
        cin >> temp1 >> temp2;
        products.push_back(make_pair(temp1, temp2));
    }
    sort(products.begin(), products.end(), comp);
    int pointer1 = 0;
    int pointer2 = N - 1;
    long long int bought = 0;
    long long int res = 0;
    while(pointer1 <= pointer2)
    {
        if(bought >= products[pointer2].second)
        {
            bought += products[pointer2].first;
            res += products[pointer2].first;
            pointer2--;
        }
        else
        {
            if(bought + products[pointer1].first > products[pointer2].second)
            {
                products[pointer1].first -= products[pointer2].second - bought;
                res += (products[pointer2].second - bought) * 2;
                bought = products[pointer2].second;
                continue;
            }
            bought += products[pointer1].first;
            res += products[pointer1].first * 2;
            pointer1++;
        }
    }
    cout << res;
    return 0;
}