#include <bits/stdc++.h>
using namespace std;


// this is brute force approach

// int peakIndexInMountainArray(vector<int>& arr)
// {
//     for (int i = 0; i < arr.size() - 1; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             return i;
//         }
//     }

//     return 0;
// }



// this is for the binary search approach


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

      int i=0;
      int j=arr.size()-1;

      while( i<=j)
      {
        int mid = i+(j-i)/2;

        if( arr[mid]<arr[mid+1])
        {
            i=mid+1;
        }
        else{
            j= mid-1;
        }
      }

      return i;
    }
};

int main()
{
    // Test Case
    vector<int> arr = {0, 2, 5, 3, 1};

    Solution sol;
    int result = sol.peakIndexInMountainArray(arr);

    cout << "Peak Index: " << result << endl;

    return 0;
}