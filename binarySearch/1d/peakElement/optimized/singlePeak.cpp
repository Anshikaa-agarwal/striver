/*
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. 
Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. 
If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, 
the next element should be considered as negative infinity.
*/
#include<iostream>
#include<vector>
using namespace std;
int singlePeak(vector<int> &arr) {
    int n=arr.size();
    if(n==1) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    int low=0, high=arr.size()-1, mid;

    while(low <= high) {
        mid = low + (high - low) / 2;

        // Check if the middle element is a peak
        if((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) {
            return arr[mid]; // Peak found, return the value
        }
        else if(mid > 0 && arr[mid - 1] > arr[mid]) {
            // If the left neighbor is greater, the peak must be on the left
            high = mid - 1;
        } else {
            // Otherwise, the peak must be on the right
            low = mid + 1;
        }
    }

    return -1; // This line is never actually reached
}
int main() {
    vector<int> arr = {3,2,1};
    cout << singlePeak(arr);
}