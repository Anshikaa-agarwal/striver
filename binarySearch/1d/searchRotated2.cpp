// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. 
// Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// Example, arr[] = {3,1,2,3,3,3,3} 

// Approach: if(arr[low]==arr[mid]==arr[high]) trim down the search space
//                                             low++;
//                                             high--;                                

#include<vector>
#include<iostream>
using namespace std;
int searchRotated2(vector<int> arr, int target) {
    int low = 0, high = arr.size()-1, mid;
    
    while(low<=high) {
        mid = (low+high)/2;
        if(arr[mid]==target) return mid;

        // trim down the search space
        while(arr[low]==arr[mid] && arr[mid]==arr[high]) {
            low++;
            high--;
            mid = (low+high)/2;
        }

        //when we have reduced array, perform search like in rotated search 1
        if(arr[low]<=arr[mid]) {
            //left half is sorted
            if(arr[low] <= target && target <= arr[mid]) {
                //left search
                high = mid-1;
            } else low = mid+1;
        }
        else if(arr[mid] <= arr[high]) {
            //right half is sorted
            if(arr[mid] <= target && target <= arr[high]) {
                //right search
                low = mid+1;
            } else high = mid-1;
        }
    }

    return -1;
}
int main() {
    vector<int> arr = {3,3,1,2,3,3,3,3};
    int target = 1;

    int search = searchRotated2(arr, target);

    if(search==-1) cout << "target element not found.";
    else cout << "Target " << target << " found at index " << search;

    return 0;
}