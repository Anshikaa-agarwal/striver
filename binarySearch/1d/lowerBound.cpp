// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lowerBound(vector<int> arr, int target) {
    int low = 0, high = arr.size()-1;

    while(low<high) {
        int mid = low + (high-low)/2;
    
        if(arr[mid]>=target) {
            // left search
            high = mid;
        }
        else if(arr[mid]<target) {
            // right search
            low = mid+1;
        }
    } 
    if(arr[low]>=target && low < arr.size()) return low;
    else return -1;
}
int main() {
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int target = 0;
    int lb = lowerBound(arr, target);
    if(lb==-1) cout << "All elements are smaller than target.";
    else cout << lb;
}