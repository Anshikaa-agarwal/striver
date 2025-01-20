/*
Median of Two Sorted Arrays of different sizes

Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. 
The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.
*/

// Approach: Using binary search
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool validSymmetry(int l1, int l2, int r1, int r2) {
    if(l1<=r2 && l2<=r1) return true;
    return false;
}
double findMedian(vector<int> arr1, vector<int> arr2) {
    // returns how many num of elements do we need to take from smaller array
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    // Ensure arr1 is the smaller array
    if (n1 > n2) {
        return findMedian(arr2, arr1); // Swap the arrays and their sizes
    }

    int low=0, high=n1, mid1, mid2, ans;

    // perform binary search from 0 to n
    while(low<=high) {
        mid1 = low + (high-low)/2; // take mid1 elements from smaller array
        mid2 = (n1+n2)/2 - mid1; // take mid2 elements from arr2

        // handle edge cases for mid1 (arr1) 
        int l1 = (mid1 == 0) ? INT32_MIN : arr1[mid1-1];
        int r1 = (mid1 == n1) ? INT32_MAX : arr1[mid1];

        // handle edge cases for mid2 (arr2)
        int l2 = (mid2 == 0) ? INT32_MIN : arr2[mid2-1];
        int r2 = (mid2 == n2) ? INT32_MAX : arr2[mid2];

        if(validSymmetry(l1,l2,r1,r2)) {
            if ((n1 + n2) % 2 == 1) {
                return max(l1, l2);
            } else {
                // If even, return average of max of left sides and min of right sides
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        } 
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return -1; 
}
int main() {
    vector<int> arr1 = {2,3,6,15};
    vector<int> arr2 = {1,3,4,7,10,12};

    cout << findMedian(arr1, arr2);
}