// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise, 
// determine the index where it would be inserted in the array while maintaining the sorted order.

// Approach: find lower bound
#include<iostream>
#include<vector>
using namespace std;
int insertPos(vector<int> arr, int x) {
    int low = 0, high = arr.size()-1, ans = arr.size();
    
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid]>=x) {
            // move left
            ans = mid;
            high = mid - 1;
        } else {
            // move right
            low = mid + 1;
        }
    }

    return ans;
}
int main() {
    vector<int> arr = {1,2,4,7};
    int x = 2;
    cout << insertPos(arr, x);
}