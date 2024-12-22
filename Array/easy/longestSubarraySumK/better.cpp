//Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k (only positive values)
#include<iostream>
#include<vector>
using namespace std;
int subarraySumK(vector<int> arr, int k) {
    int longest = 0;
    int start = 0, i = 0, sum=0, count=0;

    while(i<arr.size()) {
        sum += arr[i++];
        while(sum>k && start<i) sum -= arr[start++];
        if(sum==k) {
            count = i-start;
            longest = max(longest, count);
        }
        
    }

    return longest;
}
int main() {
    vector<int> arr = {1,2,4,-1,3};
    int k = 6;
    cout << subarraySumK(arr, k);
    return 0;
}