/*Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.*/
#include<iostream>
#include<vector>
using namespace std;
int countSubarray(vector<int> arr, int target) {
    int count = 0;
    int sum = 0;
    int start = 0, n=arr.size(), i=0;

    while(i<n) {
        sum+=arr[i++];
        while(sum>target && start<i) {
            sum-=arr[start++];
        }
        if(sum==target) count++;
    }
    return count;
}
int main() {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int count = countSubarray(arr, k);
    cout << count;
    return 0;
}