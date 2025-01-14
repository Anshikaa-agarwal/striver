// Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.
/*
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
*/
#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int> arr, int target) {
    int low = 0, high = arr.size()-1, ans = arr.size();
    while(low<=high) {
        int mid = low+(high-low)/2;
        if(arr[mid]>=target) {
            //left search
            ans = mid;
            high = mid-1;
        } else {
            // right search
            low = mid+1;
        }
    }

    return ans;
}
int upperBound(vector<int> arr, int target) {
    int low=0, high = arr.size()-1, ans = arr.size();
    
    while(low<=high) {
        int mid = low+(high-low)/2;

        if(arr[mid]>target) {
            //left shift
            ans = mid;
            high = mid-1;
        } else {
            // right search
            low = mid+1;
        }
    }

    return ans;
}
int countOccurrence(vector<int> arr, int target) {
    int start = lowerBound(arr, target);
    int end = upperBound(arr, target);

    return (end-start);
}
int main() {
    vector<int> arr = {1,1,2,2,2,2,2};
    int target = 2;
    cout << countOccurrence(arr, target);

    return 0;
}