// Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X
// when raised to the power N equals M. If the 'nth root is not an integer, return -1.

#include<iostream>
#include<vector>
using namespace std;
long long powerN(int x, int n) {
    long long ans=1;
    for(int i=1; i<=n; i++) ans*=x;
    return ans;
}
int nthRoot(int x, int n) {
    if(x==0) return 0;
    if(x==1) return 1;

    int low=1, high=x, mid, ans;

    while(low<=high) {
        mid=(low+high)/2;
        long long k=powerN(mid, n);
        
        //if mid^n=x, return mid
        if(k==x) return mid;

        //if mid^n < x, right search
        if(k<x) low=mid+1;
        else high=mid-1;
    }

    return -1;
}
int main() {
    int x=1000, n=3;
    cout << nthRoot(x,n);

    return 0;
}