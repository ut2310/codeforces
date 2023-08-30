    using namespace std;
    #include <iostream>
    #include <vector>
    #include <string>
    int main()
    {
        int Q, size;
        cin >> Q;
        for(int x = 0; x < Q; x++)
        {
            cin >> size;
            vector<int> arr;
            int temp;
            for(int i = 0; i < size; i++)
            {
                cin >> temp;
                arr.push_back(temp);
            }
            string current = "";
            int prev = 1;
            for(int i = 0; i < size; i++)
            {
                if(arr[i] == 1)
                {
                    current = current + "1";
                }
                else if(arr[i] == prev + 1)
                {
                    current = current.substr(0, current.size() - 1) + to_string(arr[i]);
                }
                else
                {
                    for(int j = current.size() - 1; j >= 0; j--)
                    {
                        int temp = current.at(j) - '0';
                        if(temp == arr[i] - 1)
                        {
                            current = current.substr(0, j) + to_string(arr[i]);
                            break;
                        }
                    }
                }
                prev = arr[i];
                for(int j = 0; j < current.size(); j++)
                {
                    if(j == 0)
                    {
                        cout << current.at(j);
                    }
                    else
                    {
                        cout << "." << current.at(j);
                    }
                }
                cout << "\n";
            }
        }
    }