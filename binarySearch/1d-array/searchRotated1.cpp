// Search in a rotated array with no duplicates
// Eg: nums[] = {4,5,6,7,1,2,3}, target = 4
#include<iostream>
#include<vector>
using namespace std;
int searchRotated1(vector<int> &nums, int target) {
    int low = 0, high = nums.size()-1;
    int mid;

    while(low <= high) {
        mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;

        // we'll find which side is sorted

        // sorted left half
        if(nums[low] < nums[mid]) {
            // if target is in left side
            if(nums[low] <= target) 
            mid=high-1;
            else
            low = mid+1;
        }
        else {
            // right side is sorted
            if(target <= nums[high])
            low = mid+1;
            else
            high=mid-1;
        }
    }


    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,1,2,3};
    cout << searchRotated1(nums, 4);
}