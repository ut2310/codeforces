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
    int T, N;
    int main()
    {
        cin >> T;
        while(Q-->0)
        {
            cin >> N;
            vector<int> arr;
            long long int sum = 0;
            for(int i = 0; i < N; i++)
            {
                int temp; cin >> temp;
                arr.push_back(temp);
                sum += temp;
            } 
            if(sum % 2 == 1)
            {
                cout << "-1\n";
            }
            else
            {
                int new temp = sum/2;

            }

        }
    }