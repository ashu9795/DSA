#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    // Test Case
    vector<int> arr = {0, 2, 5, 3, 1};

    int result = peakIndexInMountainArray(arr);

    cout << "Peak Index: " << result << endl;

    return 0;
}