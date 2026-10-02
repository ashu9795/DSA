#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int start = -1;
    int end = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == k)
        {
            if (start == -1)
            {
                start = i;
            }

            end = i;
        }
    }

    return {start, end};
}

int main()
{
    // Test Case
    vector<int> arr = {1, 2, 2, 2, 4, 5};
    int k = 2;

    pair<int, int> result = firstAndLastPosition(arr, arr.size(), k);

    cout << "First Position: " << result.first << endl;
    cout << "Last Position: " << result.second << endl;

    return 0;
}