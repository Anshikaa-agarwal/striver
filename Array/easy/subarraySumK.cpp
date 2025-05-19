// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int> &nums, int k) {
    int length = -1, sum=0, maxx=0;

    for(int i=0; i<nums.size(); i++) {
        if(sum==k) {
            if(length>maxx)
            maxx = length;

            sum=0;
            length=0;
        }

        sum+=nums[i];
        length++;

        if(sum>k) {
            sum=0;
            length=0;
        }
    }

    return max(maxx, length);
}

int main() {
    vector<int> arr = {2,3,5,1,9};
    int k=10;

    cout << longestSubarray(arr, k);

    return 0;
}