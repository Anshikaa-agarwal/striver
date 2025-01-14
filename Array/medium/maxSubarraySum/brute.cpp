// Leetcode - 53
//Given an integer array nums, find the subarray with the largest sum, and return its sum.

// o(n^3) - iterate over all subarrays
#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int> arr) {
    if(arr.size()==1) return arr[0];
    int maxx = INT8_MIN;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i; j<arr.size(); j++) {
            int sum = 0;
            for(int k=i; k<=j; k++) {
                sum += arr[k];
            }
            if(sum>maxx) maxx = sum;
        }
    }
    return maxx;
}
int main() {
    vector<int> arr = {1,2,3,-1};
    cout << maxSubarraySum(arr);
    return 0;
}