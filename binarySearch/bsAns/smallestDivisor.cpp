// Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. 
// Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, 
// the sum of the division's result is less than or equal to the given threshold value.

/*
Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/

// Approach: take an array from 1 to maximum element, if we take any larger number all divisions will yield 1 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sum(vector<int> arr, int k) {
    int s=0;
    for(int i=0; i<arr.size(); i++) {
        s+=(arr[i]+k-1)/k;
    }
    return s;
}
int divisor(vector<int> arr, int limit) {
    int low=1, high=*max_element(arr.begin(), arr.end()), mid, ans;

    while(low<=high) {
        mid=low+(high-low)/2;
        int s=sum(arr, mid);

        if(s<=limit) {
            ans = mid;
            high=mid-1;
        } else low=mid+1;
    }
    return ans;
}
int main() {
    vector<int> arr = {44,22,33,11,1};
    int limit = 5;
    cout << divisor(arr, limit);
}