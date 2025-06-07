// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
// Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int roatedArray1(vector<int> &nums, int target) {
    int n = nums.size();
    int low=0, high=nums.size()-1;
    int mid;

    while(low<=high) {
        mid = low+(high-low)/2;

        if(nums[mid] == target) return mid;
        
        // right half sorted
        if(nums[mid] <= nums[high]) {
            // found in right half
            if(nums[mid] < target && target <= nums[high]) {
                low=mid+1;
            }
            // eliminate right half
            else 
            high = mid-1;
        }
        // left half sorted
        else {
            // found in left half
            if(nums[low] <= target && target < nums[mid])
            high = mid-1;
            // eliminate left half
            else {
                low=mid+1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int target = 4;

    cout << roatedArray1(arr, target);

    return 0;
}