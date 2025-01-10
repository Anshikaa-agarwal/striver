// Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X
// when raised to the power N equals M. If the 'nth root is not an integer, return -1.

#include<iostream>
#include<vector>
using namespace std;
int powerN(int x, int n) {
    int ans=1;
    for(int i=1; i<=n; i++) ans*=x;
    return ans;
}
int nthRoot(int x, int n) {
    for(int i=0; i<x/2; i++) {
        int k = powerN(i, n);
        if(k>x) break;

        if(k==x) return i;
    }
    return -1;
}
int main() {
    int x=9, n=2;
    cout << nthRoot(x, n);
}