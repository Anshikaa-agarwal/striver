// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
// Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

// Approach: Find mid element, if arr[low] <= arr[mid] implies left half is sorted
//                                arr[mid] <= arr[high] implies right half is sorted

#include<iostream>
#include<vector>
using namespace std;
int searchRotated1(vector<int> arr, int target) {
    int low=0, high=arr.size()-1, mid;

    while(low<=high) {
        mid = low+(high-low)/2;
    }
}
int main() {
    vector<int> arr = {7,8,9,1,2,3,4,5,6};

}