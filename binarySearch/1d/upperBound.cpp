// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
// arr[index] > target
// The upper bound of a target in a sorted array is the index of the first element that is strictly greater than the target.
#include<iostream>
#include<vector>
using namespace std;
int ub(vector<int> arr, int target) {
    int low=0, high = arr.size()-1, ans = arr.size();

    while(low<=high) {
        int mid = low+(high-low)/2;
        if(arr[mid]>target) {
            // move left
            ans = mid;
            high=mid-1;
        } else {
            // move right
            low = mid + 1;
        }
    }

    if(ans<arr.size()-1 && arr[ans]>target) return ans;
    return -1;
}
int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 5;
    cout << ub(arr, target);
}