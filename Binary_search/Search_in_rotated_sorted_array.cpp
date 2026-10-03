#include <iostream>
#include <vector>
using namespace std;


// Find the index of the smallest element
// This is the rotation point
int pivot(vector<int>& arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        int mid = i + (j - i) / 2;

        if (arr[mid] > arr[j])
        {
            // Pivot is on the right side
            i = mid + 1;
        }
        else
        {
            // Pivot is at mid or on the left side
            j = mid;
        }
    }

    return i;
}


// Normal binary search on a sorted array
int searchIndex(vector<int>& arr, int start, int end, int k)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }

        if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}


// Search in rotated sorted array
int search(vector<int>& arr, int n, int k)
{
    // Find rotation point
    int pivotIndex = pivot(arr);

    // Search in left sorted part
    int ans = searchIndex(arr, 0, pivotIndex - 1, k);

    if (ans != -1)
    {
        return ans;
    }

    // Search in right sorted part
    return searchIndex(arr, pivotIndex, n - 1, k);
}


int main()
{
    // Test Case 1
    vector<int> arr1 = {5, 8, 9, 10, 1, 3, 4};
    int k1 = 4;

    cout << "Test Case 1:" << endl;
    cout << "Index: " << search(arr1, arr1.size(), k1) << endl;


    // Test Case 2
    vector<int> arr2 = {7, 8, 9, 10, 0, 1, 2, 5, 6};
    int k2 = 9;

    cout << "\nTest Case 2:" << endl;
    cout << "Index: " << search(arr2, arr2.size(), k2) << endl;


    // Test Case 3
    vector<int> arr3 = {4, 5, 6, 7, 0, 1, 2};
    int k3 = 0;

    cout << "\nTest Case 3:" << endl;
    cout << "Index: " << search(arr3, arr3.size(), k3) << endl;


    // Test Case 4
    vector<int> arr4 = {4, 5, 6, 7, 0, 1, 2};
    int k4 = 3;

    cout << "\nTest Case 4:" << endl;
    cout << "Index: " << search(arr4, arr4.size(), k4) << endl;


    // Test Case 5 - No rotation
    vector<int> arr5 = {1, 2, 3, 4, 5, 6, 7};
    int k5 = 5;

    cout << "\nTest Case 5:" << endl;
    cout << "Index: " << search(arr5, arr5.size(), k5) << endl;


    return 0;
}