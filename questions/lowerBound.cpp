// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
// Lower bound: the smallest value that is less than or equal to all the values in a given set.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lowerBound(vector<int> arr, int x) {
    int low=0, high=arr.size();
    int ans=-1, mid;

    while(low<=high) {
        mid = low + (high-low)/2;
        if(arr[mid] <= x) {
            ans=arr[mid];
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {1,2,2,3};
    int x=0;

    cout << lowerBound(arr, x);
    return 0;
}