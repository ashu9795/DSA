#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int leftsum =0;

        int ans = -1;

        for ( int i =0;i< nums.size();i++)
        {
         leftsum +=nums[i];
        }

        if(leftsum - nums[0]==0)
        {
            return 0;
        }


        int rightsum =0;
        for( int i =0;i<nums.size();i++)
        {
            leftsum -= nums[i];

            if(leftsum==rightsum)
            {
                ans = i;
                break;
            }
            rightsum+=nums[i];
        }
        return ans;

    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << "Test Case 1: " << obj.pivotIndex(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3};
    cout << "Test Case 2: " << obj.pivotIndex(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {2, 1, -1};
    cout << "Test Case 3: " << obj.pivotIndex(nums3) << endl;

    // Test Case 4
    vector<int> nums4 = {1};
    cout << "Test Case 4: " << obj.pivotIndex(nums4) << endl;

    return 0;
}