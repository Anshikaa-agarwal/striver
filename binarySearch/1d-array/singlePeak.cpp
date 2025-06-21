#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int singlePeak(vector<int> &nums) {

    int n=nums.size();
    if(n==1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-2] < nums[n-1]) return n-1;
    // we need to find max element .
    int low=0, high=nums.size()-1;
    int mid, index=0;

    while(low<=high) {
        mid = low+(high-low)/2;

        // if we are at peak element
        if((mid==0 && nums[mid] > nums[mid+1]) ||( mid==(n-1) && nums[mid] > nums[mid-1]) || (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])) 
        return mid;

        // increasing curve
        if(mid < (n-1) || nums[mid] < nums[mid+1])
        low=mid+1;
        else
        high=mid-1;
    }
    return index;
}
int main() {
    vector<int> arr = {1,2,3,4,5,3};
    cout << singlePeak(arr);
}