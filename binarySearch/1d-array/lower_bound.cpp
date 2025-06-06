// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
// Lower bound: smallest element such that arr[i] >= n

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findLowerBound(vector<int> &nums, int x) {
    int low=0, high=nums.size()-1;
    int mid, ans=nums.size();

    while(low<=high) {
        mid = low + (high-low)/2;
        if(nums[mid] >= x) {
            // this could be a possible ans, but try searching left
            ans = mid;
            high = mid-1;
        }
        else {
            low=mid+1;
        }
    }

    return ans;
}
int main() {
    vector<int> nums = {1, 3, 3, 5, 8, 9};
    int x;
    
    cout << "Enter the value to find lower bound for: ";
    cin >> x;
    
    int index = findLowerBound(nums, x);
    
    if (index == nums.size()) {
        cout << "No element found greater than or equal to " << x << endl;
    } else {
        cout << "Lower bound of " << x << " is at index " << index 
             << ", value = " << nums[index] << endl;
    }

    return 0;
}