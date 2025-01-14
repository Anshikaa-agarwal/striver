//Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k (only positive values)
// Approach: Generate all subarrays, find sum of each subarray and compare it
#include<iostream>
#include<vector>
using namespace std;
int longestSubarray(vector<int> arr, int target) {
    int longest = 0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i; j<arr.size(); j++) {
            int sum = 0;
            for(int k=i; k<=j; k++) {
                sum += arr[k];
                if(sum>target) break;
            }
            if(sum==target) {
                longest = max(longest, j-i+1);
            }
        }
    }
    return longest;
}
int main() {
    vector<int> arr = {1,2,4,1,3,1,1,1};
    int k = 6;
    cout << longestSubarray(arr, k);
    return 0;
}