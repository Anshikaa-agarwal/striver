// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. 
// If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

// Approach: Use binary search in an array of 1 to n/2
#include<iostream>
#include<vector>
using namespace std;
int sqrt(int x) {
    int ans;
    int low=0, high=x, mid;

    while(low<=high) {
        mid=(low+high)/2;
        if(mid*mid==x) return mid;

        if(mid*mid<x) {
            ans=mid;
            //right search
            low=mid+1;
        } else{
            //left search
            high=mid-1;
        }
    }

    return ans;
}
int main() {
    int x=112;
    cout << "Square root of " << x << " is " << sqrt(x);
}