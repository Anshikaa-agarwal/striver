#include<iostream>
#include<vector>
using namespace std;

int rotated2(vector<int> &nums, int target) {
    int n=nums.size();
    int low=0, high=n-1;
    int mid;

    while(low<=high) {
        mid = low+(high-low)/2;
        if(nums[mid] == target) return mid;

        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // identify sorted half

        if(nums[mid] <= nums[high]) {
            if(nums[mid] < target && target <= nums[high])
            low = mid+1;
            else
            high = mid-1;
        }
        else {
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && target < nums[mid]) 
                high = mid-1;
                else
                low=mid+1;
            }
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {3,1,2,3,3,3,3,3};
    int target = 2;

    cout << rotated2(arr, target) << endl;

    return 0;
}