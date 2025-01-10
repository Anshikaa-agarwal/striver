// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. 
// If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

// Approach: Use binary search in an array of 1 to n/2
#include<iostream>
#include<vector>
using namespace std;
int sqrt(int x) {
    int ans;
    if(x==0) return 0;
    if(x==1) return 1;
    vector<int> arr;
    for(int i=1; i<=x/2; i++) {
        arr.push_back(i);
    }

    int low=0, high=arr.size()-1, mid;

    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]*arr[mid]==x) return arr[mid];
        if(arr[mid]*arr[mid]<x) {
            ans = arr[mid];
            low = mid+1;
        } else{
            high = mid-1;
        }
    }

    return ans;
}
int main() {
    int x=0;
    cout << "Square root of " << x << " is " << sqrt(x);
}