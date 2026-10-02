#include <bits/stdc++.h>
using namespace std;

// this is brute force approach

// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     int start = -1;
//     int end = -1;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == k)
//         {
//             if (start == -1)
//             {
//                 start = i;
//             }

//             end = i;
//         }
//     }

//     return {start, end};
// }



// this is for the binary search approach ( you have to find the first occurance ad last occurance of the element in the sorted array)

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
  int first=-1;
  int last =-1;

  int i =0;
  int j = arr.size()-1;

// first occurnace 

while( i<=j)
{
    int mid = i+(j-i)/2;

    if(arr[mid]==k)
    {
        first  = mid;
        j = mid-1;
    
    }
    else if ( arr[mid] > k)
    {
        j= mid-1;
    }
    else {
        i = mid+1;
    }
}
 i =0;
   j = arr.size()-1;

// last  occurnace 

while( i<=j)
{
    int mid = i+(j-i)/2;

    if(arr[mid]==k)
    {
        last  = mid;
        i = mid+1;
    
    }
    else if ( arr[mid] > k)
    {
        j= mid-1;
    }
    else {
        i = mid+1;
    }
}

    return {first , last};
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