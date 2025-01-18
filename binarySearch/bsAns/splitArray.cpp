// Split Array - Largest Sum

/*
Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that 
the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sumArr(vector<int> arr) {
    int sum=0;
    for(int i=0; i<arr.size(); i++) sum+=arr[i];
    return sum;
}
int findK(vector<int> &arr, int maxSum) {
    // on the basis of max sum, this func returns in how many parts can we break the array
    int subarray=1, currentSum=0; //currently we're on 1st subarray which has sum=0

    for(int i=0; i<arr.size(); i++) {
        if(currentSum + arr[i] <= maxSum) {
            currentSum += arr[i];
        } else {
            subarray++;
            currentSum=arr[i];
        }
    }
    return subarray;
}
int minLargestSum(vector<int> &arr, int k) {
    // returns minimum of largest sum of k subarrays
    int n=*max_element(arr.begin(), arr.end());

    // edge cases
    if(k>arr.size()) return -1;
    if(k==arr.size()) return n;

    int low=n, high=sumArr(arr);
    int ans=-1, mid;

    while(low<=high) {
        mid=low+(high-low)/2;

        int obtainedK = findK(arr, mid); // for 'mid' max sum, we can split array into obtainedK subarrays
        if(obtainedK <= k) {
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {7,2,5,10,8};
    int k=2;

    cout << minLargestSum(arr, k);

    return 0;
}