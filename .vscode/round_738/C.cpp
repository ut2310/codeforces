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
    int t, N;
    int main()
    {
        cin >> t;
        while(t-->0)
        {   
            vector<int> input;
            cin >> N;
            for(int i = 0; i < N; i++)
            {
                int temp; cin >> temp;
                input.push_back(temp);
            }
            bool flag = false;
            int save = -1;
            for(int i = 0; i < N; i++)
            {
                if(i != N - 1)
                {
                    if(input[i] == 0 && input[i + 1] == 1)
                    {
                        flag = true;
                        save = i;
                        break;
                    }
                }
                else
                {
                    if(input[N - 1] == 0 && input[0] == 1)
                    {
                        flag = true;
                        save = N - 1;
                        break;
                    }
                }
            }
            if(!flag)
            {
                cout << "-1\n";
            }
            else
            {
                for(int i = 1; i <= save + 1; i++)
                {
                    cout << i << " ";
                }
                cout << N + 1 << " ";
                for(int i = save + 2; i <= N; i++)
                {
                    cout << i << " ";
                }
            }
        }
    }