/*
roblem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7

Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
*/

#include<iostream>
#include<vector>
using namespace std;

int floor(vector<int> &nums, int x) {
    int low=0, high=nums.size()-1;
    int mid, ans = -1;

    while(low<=high) {
        mid = low+(high-low)/2;

        if(nums[mid] <= x) {
            ans = nums[mid];
            low = mid+1;
        }
        else high = mid-1;
    }

    return ans;
}
int ceiling(vector<int> &nums, int x) {
    int low=0, high=nums.size()-1;
    int mid, ans = -1;

    while(low<=high) {
        mid = low+(high-low)/2;

        if(nums[mid] >= x) {
            ans = nums[mid];
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
}
int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 11;
    
    cout << floor(arr, x) << endl;
    cout << ceiling(arr, x) << endl;
}
