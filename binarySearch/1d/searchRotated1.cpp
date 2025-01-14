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
        int mid = (low+high)/2;
        if(arr[mid]==target) return mid;
        
        // find which half is sorted
        if(arr[low]<=arr[mid]) {
            //left half is sorted

            // now check if target lies b/w arr[low] and arr[mid]
            // if it lies, perform BS on it, otherwise eliminate it

            if(arr[low] <= target && target <= arr[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        } 
        else if(arr[mid]<=arr[high]) {
            // right half is sorted

            // check if target element lies b/w arr[mid] and arr[high]
            // if yes, apply bs here, otherwise eliminate it

            if(arr[mid]<=target && target<=arr[high]) {
                low = mid+1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int target = 1;

    int search = searchRotated1(arr, target);
    if(search==-1) cout << "target not found.";
    else cout << "Target " << target << " found at index " << search;

    return 0;
}