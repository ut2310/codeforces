using namespace std;
#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int size;
    cin >> size;
    vector<long long int> arr;
    for(int i = 0; i < size; i++)
    {
        long long int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
    int res = 0;
    long long int track = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] >= 0)
        {
            pq.push(arr[i]);
            track += arr[i];
            res++;
        } 
        else
        {
            if(!pq.empty())
            {
                track += arr[i];
                if(track >= 0)
                {
                    pq.push(arr[i]);
                    res++;
                }
                else
                {
                    long temp = pq.top();
                    pq.pop();
                    if(arr[i] > temp)
                    {
                        pq.push(arr[i]);
                        track -= temp;
                    }
                    else
                    {
                        pq.push(temp);
                        track -= arr[i];
                    }

                }
            }
        }
    }
    cout << res;


}