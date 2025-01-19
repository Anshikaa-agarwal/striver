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
int calcK(vector<int>& arr, int maxSum) {
    // on the basis of maximum sum possible, what could be the value of k
    int k=1, currSum=0;
    for(int i=0; i<arr.size(); i++) {
        if(currSum + arr[i] <= maxSum) currSum += arr[i];
        else {
            k++;
            currSum = arr[i];
        }
    }
    return k;
}
int minOfMaxSum(vector<int>& arr, int k) {
    int n=*max_element(arr.begin(), arr.end());
    
    if(k>arr.size()) return -1;
    if(k==arr.size()) return n;

    int low=n, high=sumArr(arr);
    int ans=-1, mid;

    while(low<=high) {
        mid = low + (high-low)/2;
        int newK = calcK(arr, mid);

        if(newK <= k) {
            ans = mid;
            high = mid-1;
        } else {
            low=mid+1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {7,2,5,10,8};
    int k=2;

    cout << minOfMaxSum(arr, k);

    return 0;
}